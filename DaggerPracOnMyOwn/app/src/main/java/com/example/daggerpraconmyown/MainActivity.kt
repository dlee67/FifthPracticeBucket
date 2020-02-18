package com.example.daggerpraconmyown

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.util.Log
import com.example.daggerpraconmyown.component.DaggerSomeComponent
import javax.inject.Inject

class MainActivity : AppCompatActivity() {

    @Inject
    lateinit var someClass: SomeClass

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        val someComponent = DaggerSomeComponent.create()
        someComponent.inject(this)

        Log.i("dhl", someClass.saySomething());
    }
}