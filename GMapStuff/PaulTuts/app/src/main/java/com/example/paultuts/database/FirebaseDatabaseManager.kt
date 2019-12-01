package com.example.paultuts.database

import android.util.Log
import com.google.android.gms.maps.model.LatLng
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
    private var latlongCodeRef: DatabaseReference
    private var currentLatLongCode: Long = 0

    init {
        database = FirebaseDatabase.getInstance()
        markerRef = database.getReference(MARKER_ROOT_DIR)
        latlongCodeRef = database.getReference(NEXT_LATLONG_CODE)
        markerRef.addValueEventListener(object: ValueEventListener {
            override fun onDataChange(dataSnapshot: DataSnapshot) {
                Log.i("dhl", "children count at: " + dataSnapshot.childrenCount)
                for (snapShot in dataSnapshot.children) {
                }
            }

            override fun onCancelled(databaseError: DatabaseError) {
                Log.e("dhl", databaseError.toException().toString());
            }
        });
        latlongCodeRef.addValueEventListener(object : ValueEventListener {
            override fun onDataChange(dataSnapshot: DataSnapshot) {
                currentLatLongCode = dataSnapshot.getValue(Long::class.java)!!
                Log.i("dhl", "currentMarkerCode at: " + currentLatLongCode);
            }

            override fun onCancelled(databaseError: DatabaseError) {
                Log.e("dhl", "loadPost:onCancelled", databaseError.toException())
            }
        });
    }

    fun addLatLong(marker: MarkerOptions) {
        Log.i("dhl", "Within the addMarker(), with currentMarkerCode at: " + currentLatLongCode)
        markerRef.child(LATLONG_PREFIX + currentLatLongCode.toString()).setValue(marker.position)
        latlongCodeRef.runTransaction(object : Transaction.Handler {
            override fun doTransaction(mutableData: MutableData): Transaction.Result {
                var markerCode = mutableData.getValue(Long::class.java)
                if (markerCode == null) {
                    mutableData.value = INITIAL_LATLONG_CODE
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
        private val LATLONG_PREFIX = "latlong:"
        private val INITIAL_LATLONG_CODE: Long = 1
        private val NEXT_LATLONG_CODE = "next_latlong_code"
    }
}