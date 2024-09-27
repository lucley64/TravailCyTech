package com.example.tp4

import android.content.ContentValues
import android.content.Context
import android.database.sqlite.SQLiteDatabase
import android.database.sqlite.SQLiteOpenHelper

class DatabaseHelper(context: Context) : SQLiteOpenHelper(context, "jobs.db", null, 1) {
    override fun onCreate(db: SQLiteDatabase?) {
        db?.execSQL("CREATE TABLE jobs (id INTEGER PRIMARY KEY AUTOINCREMENT, title TEXT)")
    }

    override fun onUpgrade(db: SQLiteDatabase?, oldVersion: Int, newVersion: Int) {
        db?.execSQL("DROP TABLE IF EXISTS jobs")
        onCreate(db)

    }

    fun addJob(title: String) {
        ContentValues().apply {
            put("title", title)
        }.also {
            writableDatabase.insert("jobs", null, it)
        }
    }

    fun deleteJob(jobId: Int) {
        writableDatabase.delete("jobs", "id = ?", arrayOf(jobId.toString()))
    }

    fun getAllJobs(): List<Job> {
        val jobs = mutableListOf<Job>()
        readableDatabase.rawQuery("SELECT * FROM jobs", null).use {
            while (it.moveToNext()) {
                val id = it.getInt(it.getColumnIndexOrThrow("id"))
                val title = it.getString(it.getColumnIndexOrThrow("title"))
                jobs.add(Job(id, title))
            }
        }
        return jobs
    }

    fun clearAll() {
        writableDatabase.delete("jobs", null, null)
    }


    data class Job(val id: Int, val title: String)
}