package com.example.paultuts.database

import android.content.Context
import android.util.Log
import com.google.android.gms.maps.model.Marker
import com.google.firebase.FirebaseApp
import com.google.firebase.database.DataSnapshot
import com.google.firebase.database.DatabaseError
import com.google.firebase.database.DatabaseReference
import com.google.firebase.database.FirebaseDatabase
import com.google.firebase.database.MutableData
import com.google.firebase.database.Transaction
import com.google.firebase.database.ValueEventListener

internal class FirebaseDatabaseManager {

    var database = FirebaseDatabase.getInstance()
    private var nextMarkerCode: Long = -1
    private var markerRef: DatabaseReference
    private var markerCodeRef: DatabaseReference

    init {
        database = FirebaseDatabase.getInstance()
        markerRef = database.getReference(MARKER_ROOT_DIR)
        markerCodeRef = database.getReference(NEXT_MARKER_CODE)
    }

    fun addMarker(marker: Marker) {
        markerCodeRef.runTransaction(object : Transaction.Handler {
            override fun doTransaction(mutableData: MutableData): Transaction.Result {
                var markerCode = mutableData.getValue(Long::class.java)
                if (markerCode == null) {
                    nextMarkerCode = INITIAL_MARKER_CODE
                    mutableData.value = nextMarkerCode
                    Log.i("dhl", "In the if block of markerCodeRef transaction.");
                } else {
                    mutableData.value = markerCode + 1
                    nextMarkerCode = markerCode + 1
                    markerRef.child(MARKER_PREFIX + ":" + nextMarkerCode).setValue(marker)
                    Log.i("dhl", "nextMarkerCode at: " + nextMarkerCode);
                }
                return Transaction.success(mutableData)
            }

            override fun onComplete(error: DatabaseError?, committed: Boolean, currentData: DataSnapshot?) {
                Log.i("dhl", "updateMarkerCode() complete.")
            }
        })
    }

    companion object {
        private val MARKER_ROOT_DIR = "markers"
        private val MARKER_PREFIX = "marker"
        private val INITIAL_MARKER_CODE: Long = 1
        private val NEXT_MARKER_CODE = "next_marker_code"
    }
}