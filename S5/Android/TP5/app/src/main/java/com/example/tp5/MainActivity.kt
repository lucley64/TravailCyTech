package com.example.tp5

import android.os.Bundle
import android.view.View
import android.widget.FrameLayout
import androidx.activity.enableEdgeToEdge
import androidx.appcompat.app.AppCompatActivity
import androidx.core.view.ViewCompat
import androidx.core.view.WindowInsetsCompat
import androidx.lifecycle.lifecycleScope
import com.example.tp5.databinding.ActivityMainBinding
import kotlinx.coroutines.Dispatchers
import kotlinx.coroutines.launch
import kotlinx.coroutines.withContext

class MainActivity : AppCompatActivity() {
    private val binding by lazy { ActivityMainBinding.inflate(layoutInflater) }
    private lateinit var loadingOverlay: FrameLayout

    companion object {
        init {
            System.loadLibrary("tp5")
        }
    }

    private external fun fibonacci(n: Int): Long

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        enableEdgeToEdge()
        setContentView(binding.root)
        ViewCompat.setOnApplyWindowInsetsListener(binding.main) { v, insets ->
            val systemBars = insets.getInsets(WindowInsetsCompat.Type.systemBars())
            v.setPadding(systemBars.left, systemBars.top, systemBars.right, systemBars.bottom)
            insets
        }
        loadingOverlay = binding.loadingOverlay.root
        binding.resultText.text = getString(R.string.result, "N/A")
        binding.speedText.text = getString(R.string.computing_time, 0.0f)

        binding.javaCall.setOnClickListener {
            lifecycleScope.launch {
                showLoadingOverlay()
                try {
                    val number = binding.inputNumber.text.toString().toInt()
                    val start = System.currentTimeMillis()
                    val result = withContext(Dispatchers.IO) {
                        FibonacciJv.fibonacci(number)
                    }
                    val end = System.currentTimeMillis()
                    binding.resultText.text = getString(R.string.result, result.toString())
                    binding.speedText.text =
                        getString(R.string.computing_time, (end - start) / 1000f)
                } catch (e: Exception) {
                    binding.resultText.text = getString(R.string.error, e.message)
                } catch (so: StackOverflowError) {
                    binding.resultText.text = getString(R.string.error, so.message)
                } finally {
                    hideLoadingOverlay()
                }
            }
        }

        binding.kotlinCall.setOnClickListener {
            lifecycleScope.launch {
                showLoadingOverlay()
                try {
                    val number = binding.inputNumber.text.toString().toUInt()
                    val start = System.currentTimeMillis()
                    val result = withContext(Dispatchers.IO) {
                        fibonacciKt(number)
                    }
                    val end = System.currentTimeMillis()
                    binding.resultText.text = getString(R.string.result, result.toString())
                    binding.speedText.text =
                        getString(R.string.computing_time, (end - start) / 1000f)
                } catch (e: Exception) {
                    binding.resultText.text = getString(R.string.error, e.message)
                } finally {
                    hideLoadingOverlay()
                }
            }
        }

        binding.cppCall.setOnClickListener {
            lifecycleScope.launch {
                try {
                    showLoadingOverlay()
                    val number = binding.inputNumber.text.toString().toInt()
                    val start = System.currentTimeMillis()
                    val result = withContext(Dispatchers.IO) {
                        fibonacci(number)
                    }
                    val end = System.currentTimeMillis()
                    if (result < 0) {
                        binding.resultText.text = getString(R.string.error, "Value out of range")
                    } else {
                        binding.resultText.text = getString(R.string.result, result.toString())
                    }
                    binding.speedText.text =
                        getString(R.string.computing_time, (end - start) / 1000f)
                } catch (e: Exception) {
                    binding.resultText.text = getString(R.string.error, e.message)
                } finally {
                    hideLoadingOverlay()
                }
            }
        }
    }

    private fun showLoadingOverlay() {
        loadingOverlay.visibility = View.VISIBLE
    }

    private fun hideLoadingOverlay() {
        loadingOverlay.visibility = View.GONE
    }
}