package com.example.daggerpraconmyown.module

import com.example.daggerpraconmyown.MoreClass
import dagger.Module
import dagger.Provides

@Module // Prepares for the injection.
class MoreModule {
    @Provides // Actually provides the injection.
    fun provideLocalStore() = MoreClass()
}