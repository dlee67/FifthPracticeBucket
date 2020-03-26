package com.example.myapplication

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import androidx.compose.Composable
import androidx.compose.unaryPlus
import androidx.ui.core.Text
import androidx.ui.core.dp
import androidx.ui.core.setContent
import androidx.ui.foundation.DrawImage
import androidx.ui.layout.*
import androidx.ui.res.imageResource

class MainActivity : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContent {
            NewsStory()
        }
    }

    @Composable
    fun NewsStory() {
        val image = +imageResource(R.drawable.ac_raven)

        Column (
                modifier = Spacing(16.dp)
        ) {
            Container(height = 180.dp, expanded = true) {
                DrawImage(image)
            }

            HeightSpacer(16.dp)

            Text("A day in Shark Fin Cove")
            Text("Davenport, California")
            Text("December 2018")
        }
    }

    @Composable
    fun DefaultPreview() {
        NewsStory()
    }
}