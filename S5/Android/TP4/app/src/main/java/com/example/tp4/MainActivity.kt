package com.example.tp4

import android.content.Context
import android.os.Bundle
import android.view.Menu
import android.view.MenuItem
import android.widget.ArrayAdapter
import android.widget.EditText
import androidx.activity.enableEdgeToEdge
import androidx.appcompat.app.AppCompatActivity
import androidx.appcompat.content.res.AppCompatResources
import androidx.core.view.ViewCompat
import androidx.core.view.WindowInsetsCompat
import com.example.tp4.databinding.ActivityMainBinding
import com.google.android.material.dialog.MaterialAlertDialogBuilder
import java.io.File

const val PREFS_NAME: String = "prefs"
const val PREF_USER_NAME: String = "user_name"

class MainActivity : AppCompatActivity() {
    private val binding by lazy { ActivityMainBinding.inflate(layoutInflater) }
    private lateinit var jobList: ArrayAdapter<String>
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        enableEdgeToEdge()
        setContentView(binding.root)
        ViewCompat.setOnApplyWindowInsetsListener(binding.main) { v, insets ->
            val systemBars = insets.getInsets(WindowInsetsCompat.Type.systemBars())
            v.setPadding(systemBars.left, systemBars.top, systemBars.right, systemBars.bottom)
            insets
        }

        binding.listItem.setOnItemClickListener { _, _, position, _ ->
            val jobId = jobList.getItem(position)!!.substring(1, jobList.getItem(position)!!.indexOf("]")).toInt()
            deleteJob(jobId)
        }
        updateList()

        if (getUserName().isEmpty()) {
            changeName()
        } else {
            MaterialAlertDialogBuilder(this)
                .setTitle("Hello, ${getUserName()}")
                .show()
        }

        binding.addJob.setOnClickListener { addJob() }
        setSupportActionBar(binding.materialToolbar)
    }

    private fun changeName() {
        val input = EditText(this)
        MaterialAlertDialogBuilder(this)
            .setTitle("Enter user name")
            .setView(input)
            .setPositiveButtonIcon(
                AppCompatResources.getDrawable(
                    this,
                   android.R.drawable.ic_menu_save
                )
            )
            .setPositiveButton("save") { _, _ ->
                setUserName(input.text.toString())
            }
            .setNegativeButtonIcon(
                AppCompatResources.getDrawable(
                    this,
                    android.R.drawable.ic_menu_close_clear_cancel
                )
            )
            .setNegativeButton("cancel", null)
            .show()
    }

    override fun onCreateOptionsMenu(menu: Menu?): Boolean {
        menuInflater.inflate(R.menu.main_menu, menu)
        return super.onCreateOptionsMenu(menu)
    }

    override fun onOptionsItemSelected(item: MenuItem): Boolean {
        when (item.itemId) {
            R.id.change_name -> {
                changeName()
            }
            R.id.export -> {
                writeJobsToFile()
                DatabaseHelper(this).use { it.clearAll() }
                updateList()
            }
            R.id.import_saved -> {
                val jobs = readJobsFromFile()
                jobs.forEach { job ->
                    DatabaseHelper(this).use { it.addJob(job.title) }
                }
                updateList()
            }
        }
        return super.onOptionsItemSelected(item)
    }

    private fun updateList() {
        jobList = ArrayAdapter(
            this,
            android.R.layout.simple_list_item_1,
            getAllJobs().map { job -> "[${job.id}] ${job.title}" })
        binding.listItem.adapter = jobList
    }

    private fun getUserName(): String {
        return applicationContext
            .getSharedPreferences(PREFS_NAME, Context.MODE_PRIVATE)
            .getString(PREF_USER_NAME, "")!!
    }

    private fun setUserName(userName: String) {
        applicationContext
            .getSharedPreferences(PREFS_NAME, Context.MODE_PRIVATE)
            .edit()
            .putString(PREF_USER_NAME, userName)
            .apply()
    }

    private fun addJob() {
        EditText(this).also { editText ->
            MaterialAlertDialogBuilder(this)
                .setTitle("Add job")
                .setView(editText)
                .setPositiveButtonIcon(
                    AppCompatResources.getDrawable(
                        this,
                        android.R.drawable.ic_menu_save
                    )
                )
                .setPositiveButton("save") { _, _ ->
                    DatabaseHelper(this).use { it.addJob(editText.text.toString()) }
                    updateList()
                }
                .setNegativeButtonIcon(
                    AppCompatResources.getDrawable(
                        this,
                        android.R.drawable.ic_menu_close_clear_cancel
                    )
                )
                .setNegativeButton("cancel", null)
                .show()
        }
    }

    private fun deleteJob(jobId: Int) {
        DatabaseHelper(this).use { it.deleteJob(jobId) }
        updateList()
    }

    private fun getAllJobs(): List<DatabaseHelper.Job> {
        return DatabaseHelper(this).use { it.getAllJobs() }
    }

    private fun writeJobsToFile(){
        File(filesDir, "jobs.txt").bufferedWriter().use { writer ->
            getAllJobs().forEach { job ->
                writer.write("[${job.id}] ${job.title}")
                writer.newLine()
            }
        }
    }

    private fun readJobsFromFile(): List<DatabaseHelper.Job>{
        File(filesDir, "jobs.txt").bufferedReader().use { reader ->
            val jobs = mutableListOf<DatabaseHelper.Job>()
            reader.forEachLine { line ->
                val jobId = line.substring(1, line.indexOf("]")).toInt()
                val jobTitle = line.substring(line.indexOf("]") + 2)
                jobs.add(DatabaseHelper.Job(jobId, jobTitle))
            }
            return jobs
        }
    }
}