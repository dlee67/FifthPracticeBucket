package com.example.daggerpraconmyown.component

import com.example.daggerpraconmyown.MainActivity
import com.example.daggerpraconmyown.module.MoreModule
import com.example.daggerpraconmyown.module.SomeModule
import dagger.Component

@Component(modules = [SomeModule::class, MoreModule::class])
interface SomeComponent {
    fun inject(mainActivity: MainActivity)
}