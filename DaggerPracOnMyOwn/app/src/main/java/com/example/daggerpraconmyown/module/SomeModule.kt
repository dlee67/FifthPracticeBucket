package com.example.daggerpraconmyown.module

import dagger.Module
import dagger.Provides
import com.example.daggerpraconmyown.SomeClass

@Module // Prepares for the injection.
class SomeModule {
    @Provides // Actually provides the injection.
    fun provideLocalStore() = SomeClass()
}