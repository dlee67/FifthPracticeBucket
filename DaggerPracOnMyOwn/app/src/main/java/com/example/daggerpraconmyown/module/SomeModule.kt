package com.example.daggerpraconmyown.module

import dagger.Module
import dagger.Provides
import com.example.daggerpraconmyown.SomeClass

@Module
class SomeModule {
    @Provides
    fun provideLocalStore() = SomeClass()
}