package com.example.practicewithdagger.di.component

import com.example.practicewithdagger.MainActivity
import com.example.practicewithdagger.di.LoginManager
import dagger.Component

@Component
interface LoginComponent {
    fun inject(mainActivity: MainActivity)
}