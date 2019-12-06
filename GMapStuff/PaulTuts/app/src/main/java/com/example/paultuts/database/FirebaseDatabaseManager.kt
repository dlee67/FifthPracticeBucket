package com.example.paultuts.database

import android.graphics.Bitmap
import android.graphics.BitmapFactory
import android.util.Log
import com.google.android.gms.maps.GoogleMap
import com.google.android.gms.maps.model.LatLng
import com.google.android.gms.maps.model.MarkerOptions
import com.google.firebase.database.DataSnapshot
import com.google.firebase.database.DatabaseError
import com.google.firebase.database.DatabaseReference
import com.google.firebase.database.FirebaseDatabase
import com.google.firebase.database.MutableData
import com.google.firebase.database.Transaction
import com.google.firebase.database.ValueEventListener
import com.google.firebase.storage.FirebaseStorage
import org.json.JSONObject
import java.io.ByteArrayOutputStream
import com.google.android.gms.maps.model.Marker

class FirebaseDatabaseManager(googleMap: GoogleMap) {

    var storage = FirebaseStorage.getInstance()
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
                for (snapshot in dataSnapshot.children) {
                    var lat = JSONObject(snapshot.value.toString()).get("latitude").toString().toDouble()
                    var long = JSONObject(snapshot.value.toString()).get("longitude").toString().toDouble()
                    var markerOption = MarkerOptions()
                    markerOption.position(LatLng(lat, long))
                    googleMap.addMarker(markerOption)
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

    //https://stackoverflow.com/questions/40885860/how-to-save-bitmap-to-firebase
    fun storePicture(markerTitle: String, imageBitmap: Bitmap) {
        var rootRef = storage.reference
        var childRef = rootRef.child("images/" + markerTitle)
        var baos = ByteArrayOutputStream()
        imageBitmap.compress(Bitmap.CompressFormat.JPEG, 100, baos)
        var data: ByteArray = baos.toByteArray()
        var uploadTask = childRef.putBytes(data)
        uploadTask.addOnFailureListener {
            throw it
        }.addOnSuccessListener {
            Log.i("dhl", "Image uploaded successfully.")
        }
    }

    companion object {
        private val MARKER_ROOT_DIR = "markers_root"
        private val LATLONG_PREFIX = "latlong:"
        private val INITIAL_LATLONG_CODE: Long = 1
        private val NEXT_LATLONG_CODE = "next_latlong_code"
    }
}