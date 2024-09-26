package com.example.tp3

import android.content.res.Configuration
import android.os.Bundle
import android.view.Menu
import android.view.MenuItem
import android.widget.Button
import androidx.activity.enableEdgeToEdge
import androidx.appcompat.app.AppCompatActivity
import androidx.appcompat.widget.Toolbar
import androidx.core.view.ViewCompat
import androidx.core.view.WindowInsetsCompat
import com.example.tp3.databinding.ActivityMainBinding
import com.google.android.material.dialog.MaterialAlertDialogBuilder
import java.util.Locale

class MainActivity : AppCompatActivity() {
    private lateinit var binding: ActivityMainBinding

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        enableEdgeToEdge()
        setContentView(R.layout.activity_main)
        ViewCompat.setOnApplyWindowInsetsListener(findViewById(R.id.main)) { v, insets ->
            val systemBars = insets.getInsets(WindowInsetsCompat.Type.systemBars())
            v.setPadding(systemBars.left, systemBars.top, systemBars.right, systemBars.bottom)
            insets
        }
        binding = ActivityMainBinding.inflate(layoutInflater)
        findViewById<Toolbar>(R.id.toolbar).also { setSupportActionBar(it) }
        supportFragmentManager.beginTransaction()
            .replace(R.id.main_fragment, CalculatorFragment(), "calculator_fragment").commit()

        findViewById<Button>(R.id.button_user_guide).setOnClickListener {
            val calculatorFragment = supportFragmentManager.findFragmentByTag("calculator_fragment")
            val userGuideFragment = supportFragmentManager.findFragmentByTag("user_guide_fragment")

            if (userGuideFragment != null && userGuideFragment.isVisible) {
                supportFragmentManager.beginTransaction()
                    .replace(
                        R.id.main_fragment,
                        calculatorFragment ?: CalculatorFragment(),
                        "calculator_fragment"
                    )
                    .addToBackStack(null)
                    .commit()
            } else {
                supportFragmentManager.beginTransaction()
                    .replace(
                        R.id.main_fragment,
                        userGuideFragment ?: UserGuideFragment(),
                        "user_guide_fragment"
                    )
                    .addToBackStack(null)
                    .commit()
            }
        }

        findViewById<Button>(R.id.lang_english).setOnClickListener {
            setAppLocale("en")
        }
        findViewById<Button>(R.id.lang_french).setOnClickListener {
            setAppLocale("fr")
        }

    }

    private fun setAppLocale(localeCode: String){
        val locale = Locale(localeCode)
        Locale.setDefault(locale)
        val config = Configuration()
        config.setLocale(locale)
        resources.updateConfiguration(config, resources.displayMetrics)
        recreate()
    }

    override fun onCreateOptionsMenu(menu: Menu?): Boolean {
        menuInflater.inflate(R.menu.main_menu, menu)
        return true
    }

    override fun onOptionsItemSelected(item: MenuItem): Boolean {
        when (item.itemId) {
            R.id.menu_about -> {
                MaterialAlertDialogBuilder(this)
                    .setMessage(R.string.about_text)
                    .create()
                    .show()
            }
            }
        return super.onOptionsItemSelected(item)
    }

    override fun onSaveInstanceState(outState: Bundle) {
        val calculatorFragment = supportFragmentManager.findFragmentByTag("calculator_fragment")
        val userGuideFragment = supportFragmentManager.findFragmentByTag("user_guide_fragment")
        if (userGuideFragment != null && userGuideFragment.isVisible) {
            outState.putString("fragment", "user_guide_fragment")
        } else if (calculatorFragment != null && calculatorFragment.isVisible) {
            outState.putString("fragment", "calculator_fragment")
        }
        super.onSaveInstanceState(outState)
    }

    override fun onRestoreInstanceState(savedInstanceState: Bundle) {
        val calculatorFragment = supportFragmentManager.findFragmentByTag("calculator_fragment")
        val userGuideFragment = supportFragmentManager.findFragmentByTag("user_guide_fragment")
        when (savedInstanceState.getString("fragment")) {
            "user_guide_fragment" -> {
                supportFragmentManager.beginTransaction()
                    .replace(
                        R.id.main_fragment,
                        userGuideFragment ?: UserGuideFragment(),
                        "user_guide_fragment"
                    )
                    .addToBackStack(null)
                    .commit()
            }

            "calculator_fragment" -> {
                supportFragmentManager.beginTransaction()
                    .replace(
                        R.id.main_fragment,
                        calculatorFragment ?: CalculatorFragment(),
                        "calculator_fragment"
                    ).addToBackStack(null)
                    .commit()
            }
        }
        super.onRestoreInstanceState(savedInstanceState)
    }

}