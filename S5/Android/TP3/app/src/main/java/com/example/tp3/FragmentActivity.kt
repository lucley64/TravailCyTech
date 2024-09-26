package com.example.tp3

import android.os.Bundle
import androidx.appcompat.app.AppCompatActivity
import com.example.tp3.databinding.FragmentActivityBinding

class FragmentActivity: AppCompatActivity() {
    private val binding by lazy { FragmentActivityBinding.inflate(layoutInflater) }

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(binding.root)

        binding.showFragment.setOnClickListener {
            supportFragmentManager.beginTransaction()
                .replace(R.id.fragmentContainerView, MyFragment(), "my_fragment")
                .commit()
        }

    }
}