package com.example.paultuts.database

import android.util.Log
import com.google.android.gms.maps.model.MarkerOptions
import com.google.firebase.database.DataSnapshot
import com.google.firebase.database.DatabaseError
import com.google.firebase.database.DatabaseReference
import com.google.firebase.database.FirebaseDatabase
import com.google.firebase.database.MutableData
import com.google.firebase.database.Transaction
import com.google.firebase.database.ValueEventListener

internal class FirebaseDatabaseManager {

    private var database = FirebaseDatabase.getInstance()
    private var markerRef: DatabaseReference
    private var markerCodeRef: DatabaseReference
    private var currentMarkerCode: Long = 0

    init {
        database = FirebaseDatabase.getInstance()
        markerRef = database.getReference(MARKER_ROOT_DIR)
        markerCodeRef = database.getReference(NEXT_MARKER_CODE)
        markerRef.addValueEventListener(object: ValueEventListener {
            override fun onDataChange(dataSnapshot: DataSnapshot) {
                Log.i("dhl", "children count at: " + dataSnapshot.childrenCount)
            }

            override fun onCancelled(databaseError: DatabaseError) {
                Log.e("dhl", databaseError.toException().toString());
            }
        });
        markerCodeRef.addValueEventListener(object : ValueEventListener {
            override fun onDataChange(dataSnapshot: DataSnapshot) {
                currentMarkerCode = dataSnapshot.getValue(Long::class.java)!!
                Log.i("dhl", "currentMarkerCode at: " + currentMarkerCode);
            }

            override fun onCancelled(databaseError: DatabaseError) {
                Log.e("dhl", "loadPost:onCancelled", databaseError.toException())
            }
        });
    }

    fun addMarker(marker: MarkerOptions) {
        Log.i("dhl", "Within the addMarker(), with currentMarkerCode at: " + currentMarkerCode);
        markerRef.child(MARKER_PREFIX + currentMarkerCode.toString()).setValue(marker)
        markerCodeRef.runTransaction(object : Transaction.Handler {
            override fun doTransaction(mutableData: MutableData): Transaction.Result {
                var markerCode = mutableData.getValue(Long::class.java)
                if (markerCode == null) {
                    mutableData.value = INITIAL_MARKER_CODE
                    Log.i("dhl", "In the if block of markerCodeRef transaction.");
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
        private val MARKER_ROOT_DIR = "markers_root"
        private val MARKER_PREFIX = "marker:"
        private val INITIAL_MARKER_CODE: Long = 1
        private val NEXT_MARKER_CODE = "next_marker_code"
    }
}