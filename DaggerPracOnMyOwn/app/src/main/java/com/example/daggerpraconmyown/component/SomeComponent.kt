package com.example.daggerpraconmyown.component

import com.example.daggerpraconmyown.MainActivity
import com.example.daggerpraconmyown.module.SomeModule
import dagger.Component

@Component(modules = [SomeModule::class])
interface SomeComponent {
    fun inject(mainActivity: MainActivity)
}