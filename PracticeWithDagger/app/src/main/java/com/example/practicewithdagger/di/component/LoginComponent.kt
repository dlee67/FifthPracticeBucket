package com.example.practicewithdagger.di.component

import com.example.practicewithdagger.di.LoginManager

interface LoginComponent {
    fun getLoginManager() : LoginManager
}