package com.example.daggerpraconmyown

import android.content.Intent
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.util.Log
import android.view.View
import com.example.daggerpraconmyown.com.example.daggerpraconmyown.NewActivity
import com.example.daggerpraconmyown.component.DaggerSomeComponent
import javax.inject.Inject

class MainActivity : AppCompatActivity() {

    @Inject
    lateinit var someClass: SomeClass

    @Inject
    lateinit var moreClass: MoreClass

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        val someComponent = DaggerSomeComponent.create()
        someComponent.inject(this)

        Log.i("dhl", someClass.saySomething());
        Log.i("dhl", "More class returning something "
                + moreClass.returnSomething());
    }

    fun startNewActivity(view: View) {
        startActivity(Intent(this, NewActivity::class.java))
    }
}