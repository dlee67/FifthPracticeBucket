package com.example.daggerpraconmyown.com.example.daggerpraconmyown

import android.os.Bundle
import android.util.Log
import androidx.appcompat.app.AppCompatActivity
import com.example.daggerpraconmyown.MoreMoreClass
import com.example.daggerpraconmyown.R
import com.example.daggerpraconmyown.component.DaggerMoreComponent
import javax.inject.Inject

class NewActivity : AppCompatActivity() {

    @Inject
    lateinit var sayWhat: MoreMoreClass; // Inversion of Control will look through the component,
                                        // and see which component to inject.

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_new);

        val someComponent = DaggerMoreComponent.create()
        someComponent.inject(this)

        Log.i("dhl", "Say what: " + sayWhat.sayWhat());
    }
}