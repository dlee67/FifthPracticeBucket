package com.example.paultuts

import android.Manifest
import android.content.Intent
import android.content.pm.PackageManager
import android.graphics.Bitmap
import android.graphics.BitmapFactory
import android.location.Location
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.provider.MediaStore
import android.util.Log
import android.widget.Toast
import androidx.core.app.ActivityCompat
import androidx.core.content.ContextCompat
import com.example.paultuts.database.FirebaseDatabaseManager

import com.google.android.gms.location.*
import com.google.android.gms.maps.CameraUpdateFactory
import com.google.android.gms.maps.GoogleMap
import com.google.android.gms.maps.OnMapReadyCallback
import com.google.android.gms.maps.SupportMapFragment
import com.google.android.gms.maps.model.LatLng
import com.google.android.gms.maps.model.Marker
import com.google.android.gms.maps.model.MarkerOptions


class MapsActivity : AppCompatActivity(), OnMapReadyCallback,
                        GoogleMap.OnMyLocationButtonClickListener,
                        GoogleMap.OnMyLocationClickListener,
                        GoogleMap.OnMapClickListener,
                        GoogleMap.OnMarkerClickListener{

    lateinit var firebaseDatabaseManager: FirebaseDatabaseManager

    private var markerTitle: String = ""
    private lateinit var mMap: GoogleMap
    private lateinit var fusedLocationClient: FusedLocationProviderClient
    private lateinit var locationCallback: LocationCallback

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_maps)
        // Creates a new instance of FusedLocationProviderClient, which is a basic location API.
        fusedLocationClient = LocationServices.getFusedLocationProviderClient(this)
        // Like the beneath the lines suggests, that where activity_maps.xml is used.
        val mapFragment = supportFragmentManager
            .findFragmentById(R.id.map) as SupportMapFragment
        // Notice how this entire activity inherits OnMapReadyCallback.
        // https://developers.google.com/android/reference/com/google/android/gms/maps/OnMapReadyCallback.html
        // And notice how Paul's overriding functions like onMapReady.
        mapFragment.getMapAsync(this)
    }

    // https://developers.google.com/android/reference/com/google/android/gms/maps/OnMapReadyCallback.html#onMapReady(com.google.android.gms.maps.GoogleMap)
    override fun onMapReady(googleMap: GoogleMap) {
        // https://developers.google.com/android/reference/com/google/android/gms/maps/GoogleMap.html
        mMap = googleMap

        firebaseDatabaseManager = FirebaseDatabaseManager(mMap)

        if (ContextCompat.checkSelfPermission(this,
                Manifest.permission.ACCESS_FINE_LOCATION) == PackageManager.PERMISSION_GRANTED &&
            ContextCompat.checkSelfPermission(this,
                Manifest.permission.CAMERA) == PackageManager.PERMISSION_GRANTED &&
            ContextCompat.checkSelfPermission(this,
                Manifest.permission.WRITE_EXTERNAL_STORAGE) == PackageManager.PERMISSION_GRANTED) {
            initMap()
        } else {
            ActivityCompat.requestPermissions(this,
                arrayOf(Manifest.permission.ACCESS_FINE_LOCATION,
                    Manifest.permission.WRITE_EXTERNAL_STORAGE,
                    Manifest.permission.CAMERA),
                LOCATION_PERMISSION)
        }
    }

    override fun onRequestPermissionsResult(
        requestCode: Int,
        permissions: Array<out String>,
        grantResults: IntArray
    ) {
        super.onRequestPermissionsResult(requestCode,
            permissions,
            grantResults)
        if (requestCode == LOCATION_PERMISSION) {
            if (permissions.size == 1 &&
                permissions[0] == Manifest.permission.ACCESS_FINE_LOCATION &&
                grantResults[0] == PackageManager.PERMISSION_GRANTED
            ) {
                initMap()
            }
        }
    }

    override fun onMapClick(p0: LatLng?) {
        if (p0 != null) {
            val markerOptions = MarkerOptions()
            markerTitle = p0.latitude.toString() + ":" + p0.longitude.toString()
            markerOptions.position(p0)
            markerOptions.title(markerTitle)
            mMap.animateCamera(CameraUpdateFactory.newLatLng(p0))
            mMap.addMarker(markerOptions)
            firebaseDatabaseManager.addLatLong(markerOptions)
            takePicture()
        }
    }

    override fun onMyLocationButtonClick(): Boolean {
        Toast.makeText(this, "my location button click", Toast.LENGTH_LONG).show()
        return false
    }

    override fun onMyLocationClick(location: Location) {
        Toast.makeText(this, "my location click", Toast.LENGTH_LONG).show()
    }

    override fun onMarkerClick(marker: Marker): Boolean {
        Log.i("dhl", "Within onMarkerClick of MapsActivity.")
        var latLng = marker.position
        var imageName = "images/" + latLng.latitude + ":" + latLng.longitude
        var image = firebaseDatabaseManager.storage.reference.child(imageName)
        Log.i("dhl", "ImageName at: " + imageName)
        image.getBytes(ONE_MEGABYTE.toLong()).addOnSuccessListener {
            var bitmap = BitmapFactory.decodeByteArray(it, 0, it.size)
            // So ... that above there needs to be chucked into something that can display an image.
            var showImage = Intent(this, ShowImageActivity::class.java)
            showImage.putExtra("bitmap", bitmap)
            startActivity(showImage)
        }.addOnFailureListener {
            throw it
        }
        return true
    }

    override fun onResume() {
        super.onResume()
        if( ::mMap.isInitialized ) {
            initLocationTracking()
        }
    }

    override fun onPause() {
        super.onPause()
        fusedLocationClient.removeLocationUpdates(locationCallback)
    }

    private fun initMap() {
        mMap.isMyLocationEnabled = true
        mMap.setOnMyLocationButtonClickListener(this) // Invokes onMyLocationButtonClick in this activity.
        mMap.setOnMyLocationClickListener(this) // Invokes onMyLocationClick in this activity.
        mMap.setOnMapClickListener(this)
        mMap.setOnMarkerClickListener(this)
        initLocationTracking()
    }

    private fun initLocationTracking() {
        // https://developers.google.com/android/reference/com/google/android/gms/location/LocationCallback
        locationCallback = object : LocationCallback() {
            override fun onLocationResult(locationResult: LocationResult?) {
                locationResult ?: return
                for (location in locationResult.locations){
                    updateMapLocation(location)
                }
            }
        }

        fusedLocationClient.requestLocationUpdates(
            LocationRequest(),
            locationCallback,
            null)
    }

    private fun updateMapLocation(location: Location?) {
        mMap.moveCamera(CameraUpdateFactory.newLatLng(LatLng(
            location?.latitude ?: 0.0,
            location?.longitude ?: 0.0)))

        mMap.moveCamera(CameraUpdateFactory.zoomTo(15.0f))
    }

    private fun takePicture() {
        Intent(MediaStore.ACTION_IMAGE_CAPTURE).also { takePictureIntent ->
            takePictureIntent.resolveActivity(packageManager)?.also {
                startActivityForResult(takePictureIntent, REQUEST_IMAGE_CAPTURE)
            }
        }
    }

    override fun onActivityResult(requestCode: Int, resultCode: Int, data: Intent?) {
        super.onActivityResult(requestCode, resultCode, data)
        if (requestCode == REQUEST_IMAGE_CAPTURE && resultCode == RESULT_OK) {
            val imageBitmap = data?.extras?.get("data") as Bitmap
            firebaseDatabaseManager.storePicture(markerTitle, imageBitmap)
        }
    }

    companion object {
        private val ONE_MEGABYTE = 1024 * 1024
        private val REQUEST_IMAGE_CAPTURE = 41
        private val LOCATION_PERMISSION = 42
    }
}
