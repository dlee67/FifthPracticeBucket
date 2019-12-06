package com.example.paultuts

import android.graphics.Bitmap
import android.os.Bundle
import android.widget.ImageView
import androidx.appcompat.app.AppCompatActivity

class ShowImageActivity: AppCompatActivity() {

    override fun onCreate(savedInstance: Bundle?) {
        super.onCreate(savedInstance)
        setContentView(R.layout.activity_image)
        findViewById<ImageView>(R.id.key_image).setImageBitmap(
            intent.getParcelableExtra<Bitmap>("bitmap"))
    }

}