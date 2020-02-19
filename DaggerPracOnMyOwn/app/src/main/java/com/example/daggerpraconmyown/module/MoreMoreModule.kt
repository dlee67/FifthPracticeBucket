package com.example.daggerpraconmyown.module

import com.example.daggerpraconmyown.MoreMoreClass
import dagger.Module
import dagger.Provides

@Module
class MoreMoreModule {
    @Provides
    fun provideMoreMoreClass() = MoreMoreClass();
}