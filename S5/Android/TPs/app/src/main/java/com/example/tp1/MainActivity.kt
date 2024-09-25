package com.example.tp1

import android.os.Bundle
import android.widget.Button
import android.widget.RadioGroup
import android.widget.TextView
import androidx.activity.enableEdgeToEdge
import androidx.appcompat.app.AppCompatActivity
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

        val convertButton = findViewById<Button>(R.id.convert_button)
        convertButton.setOnClickListener { convert() }
    }

    private fun convert() {
        val currencyInput = findViewById<TextView>(R.id.currency_input)
        val currencyOutput = findViewById<TextView>(R.id.currency_output)
        val currencyInputList = findViewById<RadioGroup>(R.id.currency_input_list)
        val currencyOutputList = findViewById<RadioGroup>(R.id.currency_output_list)
        val inputCurrency = currencyInputList.checkedRadioButtonId
        val outputCurrency = currencyOutputList.checkedRadioButtonId
        val inputValue = currencyInput.text.toString().toFloatOrNull()
        val outputValue = if (inputValue == null) "Please enter a valid number" else when (inputCurrency) {
            R.id.input_euro -> when (outputCurrency) {
                R.id.output_us_dollar -> "$inputValue ${getString(R.string.euro)} -> ${inputValue * 1.12} ${getString(R.string.us_dollar)}"
                R.id.output_japanese_yen -> "$inputValue ${getString(R.string.euro)} -> ${inputValue * 161.25} ${getString(R.string.japanese_yen)}"
                R.id.output_south_korean_won -> "$inputValue ${getString(R.string.euro)} -> ${inputValue * 1_490.03} ${getString(R.string.south_korean_won)}"
                R.id.output_pound_sterling -> "$inputValue ${getString(R.string.euro)} -> ${inputValue * 0.84} ${getString(R.string.pound_sterling)}"
                R.id.output_mexican_peso -> "$inputValue ${getString(R.string.euro)} -> ${inputValue * 21.66} ${getString(R.string.mexican_peso)}"
                R.id.output_russian_ruble -> "$inputValue ${getString(R.string.euro)} -> ${inputValue * 103.56} ${getString(R.string.russian_ruble)}"
                else -> "$inputValue ${getString(R.string.euro)} -> $inputValue ${getString(R.string.euro)}"
            }

            R.id.input_us_dollar -> when (outputCurrency) {
                R.id.output_euro -> "$inputValue ${getString(R.string.us_dollar)} -> ${inputValue * 0.89} ${getString(R.string.euro)}"
                R.id.output_japanese_yen -> "$inputValue ${getString(R.string.us_dollar)} -> ${inputValue * 144.16} ${getString(R.string.japanese_yen)}"
                R.id.output_south_korean_won -> "$inputValue ${getString(R.string.us_dollar)} -> ${inputValue * 1_331.83} ${getString(R.string.south_korean_won)}"
                R.id.output_pound_sterling -> "$inputValue ${getString(R.string.us_dollar)} -> ${inputValue * 0.75} ${getString(R.string.pound_sterling)}"
                R.id.output_mexican_peso -> "$inputValue ${getString(R.string.us_dollar)} -> ${inputValue * 19.36} ${getString(R.string.mexican_peso)}"
                R.id.output_russian_ruble -> "$inputValue ${getString(R.string.us_dollar)} -> ${inputValue * 92.58} ${getString(R.string.russian_ruble)}"
                else -> "$inputValue ${getString(R.string.us_dollar)} -> $inputValue ${getString(R.string.us_dollar)}"
            }

            R.id.input_japanese_yen -> when (outputCurrency) {
                R.id.output_euro -> "$inputValue ${getString(R.string.japanese_yen)} -> ${inputValue * 0.0062} ${getString(R.string.euro)}"
                R.id.output_us_dollar -> "$inputValue ${getString(R.string.japanese_yen)} -> ${inputValue * 0.0069} ${getString(R.string.us_dollar)}"
                R.id.output_south_korean_won -> "$inputValue ${getString(R.string.japanese_yen)} -> ${inputValue * 9.24} ${getString(R.string.south_korean_won)}"
                R.id.output_pound_sterling -> "$inputValue ${getString(R.string.japanese_yen)} -> ${inputValue * 0.0052} ${getString(R.string.pound_sterling)}"
                R.id.output_mexican_peso -> "$inputValue ${getString(R.string.japanese_yen)} -> ${inputValue * 0.13} ${getString(R.string.mexican_peso)}"
                R.id.output_russian_ruble -> "$inputValue ${getString(R.string.japanese_yen)} -> ${inputValue * 0.64} ${getString(R.string.russian_ruble)}"
                else -> "$inputValue ${getString(R.string.japanese_yen)} -> $inputValue ${getString(R.string.japanese_yen)}"
            }

            R.id.input_south_korean_won -> when (outputCurrency) {
                R.id.output_euro -> "$inputValue ${getString(R.string.south_korean_won)} -> ${inputValue * 0.00067} ${getString(R.string.euro)}"
                R.id.output_us_dollar -> "$inputValue ${getString(R.string.south_korean_won)} -> ${inputValue * 0.00075} ${getString(R.string.us_dollar)}"
                R.id.output_japanese_yen -> "$inputValue ${getString(R.string.south_korean_won)} -> ${inputValue * 0.11} ${getString(R.string.japanese_yen)}"
                R.id.output_pound_sterling -> "$inputValue ${getString(R.string.south_korean_won)} -> ${inputValue * 0.0000056} ${getString(R.string.pound_sterling)}"
                R.id.output_mexican_peso -> "$inputValue ${getString(R.string.south_korean_won)} -> ${inputValue * 0.015} ${getString(R.string.mexican_peso)}"
                R.id.output_russian_ruble -> "$inputValue ${getString(R.string.south_korean_won)} -> ${inputValue * 0.07} ${getString(R.string.russian_ruble)}"
                else -> "$inputValue ${getString(R.string.south_korean_won)} -> $inputValue ${getString(R.string.south_korean_won)}"
            }

            R.id.input_pound_sterling -> when (outputCurrency) {
                R.id.output_euro -> "$inputValue ${getString(R.string.pound_sterling)} -> ${inputValue * 1.2} ${getString(R.string.euro)}"
                R.id.output_us_dollar -> "$inputValue ${getString(R.string.pound_sterling)} -> ${inputValue * 1.34} ${getString(R.string.us_dollar)}"
                R.id.output_japanese_yen -> "$inputValue ${getString(R.string.pound_sterling)} -> ${inputValue * 192.71} ${getString(R.string.japanese_yen)}"
                R.id.output_south_korean_won -> "$inputValue ${getString(R.string.pound_sterling)} -> ${inputValue * 1_781.02} ${getString(R.string.south_korean_won)}"
                R.id.output_mexican_peso -> "$inputValue ${getString(R.string.pound_sterling)} -> ${inputValue * 25.89} ${getString(R.string.mexican_peso)}"
                R.id.output_russian_ruble -> "$inputValue ${getString(R.string.pound_sterling)} -> ${inputValue * 123.77} ${getString(R.string.russian_ruble)}"
                else -> "$inputValue ${getString(R.string.pound_sterling)} -> $inputValue ${getString(R.string.pound_sterling)}"
            }

            R.id.input_mexican_peso -> when (outputCurrency) {
                R.id.output_euro -> "$inputValue ${getString(R.string.mexican_peso)} -> ${inputValue * 0.046} ${getString(R.string.euro)}"
                R.id.output_us_dollar -> "$inputValue ${getString(R.string.mexican_peso)} -> ${inputValue * 0.052} ${getString(R.string.us_dollar)}"
                R.id.output_japanese_yen -> "$inputValue ${getString(R.string.mexican_peso)} -> ${inputValue * 7.44} ${getString(R.string.japanese_yen)}"
                R.id.output_south_korean_won -> "$inputValue ${getString(R.string.mexican_peso)} -> ${inputValue * 68.79} ${getString(R.string.south_korean_won)}"
                R.id.output_pound_sterling -> "$inputValue ${getString(R.string.mexican_peso)} -> ${inputValue * 0.039} ${getString(R.string.pound_sterling)}"
                R.id.output_russian_ruble -> "$inputValue ${getString(R.string.mexican_peso)} -> ${inputValue * 4.78} ${getString(R.string.russian_ruble)}"
                else -> "$inputValue ${getString(R.string.mexican_peso)} -> $inputValue ${getString(R.string.mexican_peso)}"
            }

            R.id.input_russian_ruble -> when (outputCurrency) {
                R.id.output_euro -> "$inputValue ${getString(R.string.russian_ruble)} -> ${inputValue * 0.0097} ${getString(R.string.euro)}"
                R.id.output_us_dollar -> "$inputValue ${getString(R.string.russian_ruble)} -> ${inputValue * 0.011} ${getString(R.string.us_dollar)}"
                R.id.output_japanese_yen -> "$inputValue ${getString(R.string.russian_ruble)} -> ${inputValue * 1.56} ${getString(R.string.japanese_yen)}"
                R.id.output_south_korean_won -> "$inputValue ${getString(R.string.russian_ruble)} -> ${inputValue * 14.39} ${getString(R.string.south_korean_won)}"
                R.id.output_pound_sterling -> "$inputValue ${getString(R.string.russian_ruble)} -> ${inputValue * 0.0081} ${getString(R.string.pound_sterling)}"
                R.id.output_mexican_peso -> "$inputValue ${getString(R.string.russian_ruble)} -> ${inputValue * 0.21} ${getString(R.string.mexican_peso)}"
                else -> "$inputValue ${getString(R.string.russian_ruble)} -> $inputValue ${getString(R.string.russian_ruble)}"
            }

            else -> "$inputValue ${getString(R.string.euro)} -> $inputValue ${getString(R.string.euro)}"
        }

        currencyOutput.text = outputValue
    }
}