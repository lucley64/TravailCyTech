package com.example.tp2

import android.graphics.drawable.ColorDrawable
import android.os.Bundle
import android.widget.Button
import android.widget.TextView
import androidx.activity.enableEdgeToEdge
import androidx.appcompat.app.AppCompatActivity
import androidx.constraintlayout.widget.ConstraintLayout
import androidx.core.view.ViewCompat
import androidx.core.view.WindowInsetsCompat
import androidx.core.view.children

class ColorPickerActivity : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        enableEdgeToEdge()
        setContentView(R.layout.color_picker_activity)
        ViewCompat.setOnApplyWindowInsetsListener(findViewById(R.id.color_picker)) { v, insets ->
            val systemBars = insets.getInsets(WindowInsetsCompat.Type.systemBars())
            v.setPadding(systemBars.left, systemBars.top, systemBars.right, systemBars.bottom)
            insets
        }

        setResult(RESULT_OK, intent)

        findViewById<Button>(R.id.go_back).also { button -> button.setOnClickListener { finish() } }

        findViewById<ConstraintLayout>(R.id.colors_vertical).also { layout ->
            layout.children.forEach { view ->
                view.setOnClickListener {
                    findViewById<TextView>(R.id.color_picked_text).also { _ ->
                        val background = view.background
                        if (background is ColorDrawable) {
                            findViewById<ConstraintLayout>(R.id.color_picker).setBackgroundColor(background.color)
                            intent.putExtra("picked_color", background.color)
                        }
                    }
                }
            }
        }
    }

}