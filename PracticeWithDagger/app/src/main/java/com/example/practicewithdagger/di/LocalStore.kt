package com.example.practicewithdagger.di

import android.util.Log
import javax.inject.Inject

class LocalStore  @Inject constructor(){
    fun saveUserToken(token: String) {
        Log.d("LocalStore","saveUserToken($token)")
    }
}