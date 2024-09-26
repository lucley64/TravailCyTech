package com.example.tp3

import android.os.Bundle
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import androidx.core.view.children
import androidx.fragment.app.Fragment
import com.example.tp3.databinding.CalculatorFragmentBinding
import com.google.android.material.button.MaterialButton
import com.google.android.material.snackbar.Snackbar

private const val s = "Please input a number and a modulo"

class CalculatorFragment : Fragment() {
    private var _binding: CalculatorFragmentBinding? = null
    private val binding get() = _binding!!

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
    }

    override fun onCreateView(
        inflater: LayoutInflater,
        container: ViewGroup?,
        savedInstanceState: Bundle?
    ): View {
        _binding = CalculatorFragmentBinding.inflate(inflater, container, false)
        binding.constraintLayout.children.filterIsInstance<MaterialButton>().forEach { button ->
            button.setOnClickListener {
                when (button.id) {
                    R.id.button_back -> binding.textInputEditText.setText(
                        "${binding.textInputEditText.text}".dropLast(
                            1
                        )
                    )

                    R.id.button_reset -> binding.textInputEditText.setText("")
                    else -> binding.textInputEditText.setText("${binding.textInputEditText.text}${button.text}")
                }
            }.also {
                button.setOnLongClickListener {
                    if (button.id == R.id.button_back || button.id == R.id.button_reset)
                        binding.buttonModulo.text = getString(R.string.modulo_of_, 0)
                    else
                        binding.buttonModulo.text =
                            getString(R.string.modulo_of_, button.text.toString().toInt())
                    true
                }

            }
        }
        binding.buttonModulo.text = getString(R.string.modulo_of_, 0)
        binding.buttonModulo.setOnClickListener {
            val modulo = binding.buttonModulo.text.toString().last()
            if (container != null) {
                if (modulo != '0' && binding.textInputEditText.text.toString().isNotEmpty()) {
                    Snackbar.make(
                        container,
                        getString(
                            R.string.modulo_result,
                            binding.textInputEditText.text.toString(),
                            modulo.code - '0'.code,
                            binding.textInputEditText.text.toString()
                                .toInt() % (modulo.code - '0'.code)
                        ),
                        Snackbar.LENGTH_SHORT
                    ).show()
                } else {
                    Snackbar.make(
                        container,
                        getString(R.string.invalid_result),
                        Snackbar.LENGTH_SHORT
                    ).show()
                }
            }
        }

        return binding.root
    }

    override fun onSaveInstanceState(outState: Bundle) {
        if (_binding != null) {
            outState.putString("text", binding.textInputEditText.text.toString())
            outState.putString("button", binding.buttonModulo.text.toString())
        }
        super.onSaveInstanceState(outState)
    }

    override fun onViewStateRestored(savedInstanceState: Bundle?) {
        if (_binding != null) {
            binding.textInputEditText.setText(savedInstanceState?.getString("text"))
            binding.buttonModulo.text =
                if (savedInstanceState?.getString("button") != null) savedInstanceState.getString("button") else getString(
                    R.string.modulo_of_, 0
                )
        }
        super.onViewStateRestored(savedInstanceState)
    }

    override fun onDestroyView() {
        super.onDestroyView()
        _binding = null
    }
}