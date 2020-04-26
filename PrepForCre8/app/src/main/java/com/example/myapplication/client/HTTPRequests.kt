package com.example.myapplication.client

import android.app.Application
import io.ktor.client.HttpClient
import io.ktor.client.engine.cio.CIO
import io.ktor.client.features.json.GsonSerializer
import io.ktor.client.features.json.JsonFeature

class HTTPRequests : Application() {
    override fun onCreate() {
        super.onCreate()
        setupKtor()
    }

    private fun setupKtor() {
        HttpClient(CIO) {
            install(JsonFeature) {
                serializer = GsonSerializer()
            }
        }
    }
}