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

internal class FirebaseDatabaseManager(context: Context) {

    var database = FirebaseDatabase.getInstance()
    private var nextMarkerCode: Long = -1
    private var markerRef: DatabaseReference
    private var markerCodeRef: DatabaseReference
    private var firebaseReader = object : ValueEventListener {
        override fun onDataChange(dataSnapshot: DataSnapshot) {
            return dataSnapshot.getValue() as Unit;
        }

        override fun onCancelled(error: DatabaseError) {
            Log.e("dhl", error.toString());
        }
    }

    init {
        database = FirebaseDatabase.getInstance()
        markerRef = database.getReference(MARKER_ROOT_DIR)
        markerCodeRef = database.getReference(NEXT_MARKER_CODE)
    }

    fun addMarker(marker: Marker) {
        var newMarkerCode = getValue().toString()
        var newMarker: HashMap<String, Marker> = HashMap()
        newMarker.put(newMarkerCode, marker)
        markerRef.child(MARKER_PREFIX + ":" + newMarkerCode).setValue(newMarker)
    }

    fun getValue(): Long {
        // They named the function as "onDataChange," but it will fetch you the data,
        // even without any deliberate changes from my side.
        markerCodeRef.addValueEventListener(firebaseReader)
        markerCodeRef.removeEventListener(firebaseReader) // If I don't do this, the application crashes.
        return nextMarkerCode
    }

    fun updateMarkerCode() {
        markerCodeRef.runTransaction(object : Transaction.Handler {
            override fun doTransaction(mutableData: MutableData): Transaction.Result {
                var markerCode = mutableData.getValue(Long::class.java)
                if (markerCode == null) {
                    markerCode = INITIAL_MARKER_CODE
                } else {
                    mutableData.value = markerCode + 1
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