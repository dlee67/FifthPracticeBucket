package com.example.paultuts

import android.content.Intent
import android.os.Bundle
import android.widget.Button
import androidx.appcompat.app.AppCompatActivity

class MainActivity: AppCompatActivity() {

    override fun onCreate(savedInstance: Bundle?) {
        super.onCreate(savedInstance)
        setContentView(R.layout.activity_main)
        findViewById<Button>(R.id.start_map).setOnClickListener {
            startActivity(Intent(this, MapsActivity::class.java))
        }
    }
}