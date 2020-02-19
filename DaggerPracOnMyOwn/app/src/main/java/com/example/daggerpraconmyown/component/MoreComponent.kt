package com.example.daggerpraconmyown.component

import com.example.daggerpraconmyown.com.example.daggerpraconmyown.NewActivity
import com.example.daggerpraconmyown.module.MoreMoreModule
import dagger.Component

@Component(modules = [MoreMoreModule::class])
interface MoreComponent {
    fun inject(newActivity: NewActivity)
}