package com.example.androidpresentation

import android.media.MediaPlayer
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.view.View

class MainActivity : AppCompatActivity() {

    var mediaPlayer: MediaPlayer? = null

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        this.mediaPlayer = MediaPlayer()
    }

    fun oneClicked(v: View) {
        if (mediaPlayer?.isPlaying!!) {
            mediaPlayer?.stop()
        }
        mediaPlayer = MediaPlayer.create(applicationContext, R.raw.armored_core_gb_shining)
        mediaPlayer?.start()
    }

    fun twoClicked(v: View) {
        if (mediaPlayer?.isPlaying!!) {
            mediaPlayer?.stop()
        }
        mediaPlayer = MediaPlayer.create(applicationContext, R.raw.megaman_x5_character_select)
        mediaPlayer?.start()
    }

    fun threeClicked(v: View) {
        if (mediaPlayer?.isPlaying!!) {
            mediaPlayer?.stop()
        }
        mediaPlayer = MediaPlayer.create(applicationContext, R.raw.metal_wolf_good_feather)
        mediaPlayer?.start()
    }
}