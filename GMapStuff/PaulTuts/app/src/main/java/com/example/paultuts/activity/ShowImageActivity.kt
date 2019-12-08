package com.example.paultuts.activity

import android.graphics.Bitmap
import android.os.Bundle
import android.widget.ImageView
import androidx.appcompat.app.AppCompatActivity
import com.example.paultuts.R

class ShowImageActivity: AppCompatActivity() {

    override fun onCreate(savedInstance: Bundle?) {
        super.onCreate(savedInstance)
        setContentView(R.layout.activity_image)
        findViewById<ImageView>(R.id.key_image).setImageBitmap(
            intent.getParcelableExtra<Bitmap>("bitmap"))
    }

}