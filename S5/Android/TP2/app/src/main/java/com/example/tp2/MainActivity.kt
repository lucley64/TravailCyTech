package com.example.tp2

import android.content.Intent
import android.net.Uri
import android.os.Bundle
import android.provider.ContactsContract
import android.util.Log
import android.widget.Button
import androidx.activity.enableEdgeToEdge
import androidx.activity.result.contract.ActivityResultContracts
import androidx.appcompat.app.AppCompatActivity
import androidx.constraintlayout.widget.ConstraintLayout
import androidx.core.view.ViewCompat
import androidx.core.view.WindowInsetsCompat

class MainActivity : AppCompatActivity() {

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        enableEdgeToEdge()
        setContentView(R.layout.activity_main)
        ViewCompat.setOnApplyWindowInsetsListener(findViewById(R.id.main)) { v, insets ->
            val systemBars = insets.getInsets(WindowInsetsCompat.Type.systemBars())
            v.setPadding(systemBars.left, systemBars.top, systemBars.right, systemBars.bottom)
            insets
        }

        Intent(this, BackgroundMusic::class.java).also { startService(it) }

        val pokemonButton = findViewById<Button>(R.id.favorite_pokémon)
        pokemonButton.setOnClickListener {
            Intent(Intent.ACTION_VIEW, Uri.parse("https://www.dragonflycave.com/favorite.html")).also {startActivity(it)}
        }

        val activityStartForResult = registerForActivityResult(ActivityResultContracts.StartActivityForResult()) { result ->
            findViewById<ConstraintLayout>(R.id.main).setBackgroundColor(
                result.data?.getIntExtra(
                    "picked_color",
                    0
                )!!
            )
        }

        findViewById<Button>(R.id.favorite_color).also { colorButton ->
            colorButton.setOnClickListener {
                activityStartForResult.launch(Intent(this, ColorPickerActivity::class.java))
            }
        }

        val contactActivityStartForResult = registerForActivityResult(ActivityResultContracts.StartActivityForResult()) { result ->
            if (result.resultCode == RESULT_OK) {
                val cursor = contentResolver.query(result.data?.data!!, null, null, null, null)
                val name = cursor?.use {
                    it.moveToFirst()
                    val name = it.getColumnIndex(ContactsContract.Contacts.DISPLAY_NAME)
                    it.getString(name)
                }
                Log.i("MainActivity", "Contact selected ${name}")
            }
        }

        findViewById<Button>(R.id.favorite_contact).also { contactButton ->
            contactButton.setOnClickListener {
                contactActivityStartForResult.launch(Intent(Intent.ACTION_PICK, ContactsContract.Contacts.CONTENT_URI))
            }
        }
    }
}