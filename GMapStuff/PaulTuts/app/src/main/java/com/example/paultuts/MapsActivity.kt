package com.example.paultuts

import android.Manifest
import android.content.pm.PackageManager
import android.location.Location
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.widget.Toast
import androidx.core.app.ActivityCompat
import androidx.core.content.ContextCompat

import com.google.android.gms.location.*
import com.google.android.gms.maps.CameraUpdateFactory
import com.google.android.gms.maps.GoogleMap
import com.google.android.gms.maps.OnMapReadyCallback
import com.google.android.gms.maps.SupportMapFragment
import com.google.android.gms.maps.model.LatLng
import android.text.method.TextKeyListener.clear
import com.google.android.gms.maps.model.MarkerOptions
import com.google.android.gms.maps.GoogleMap.OnMapClickListener
import androidx.core.app.ComponentActivity.ExtraData
import androidx.core.content.ContextCompat.getSystemService
import android.icu.lang.UCharacter.GraphemeClusterBreak.T



class MapsActivity : AppCompatActivity(), OnMapReadyCallback,
                        GoogleMap.OnMyLocationButtonClickListener,
                        GoogleMap.OnMyLocationClickListener,
                        GoogleMap.OnMapClickListener {

    private lateinit var mMap: GoogleMap
    private val LOCATION_PERMISSION = 42
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

        if (ContextCompat.checkSelfPermission(this, Manifest.permission.ACCESS_FINE_LOCATION)
            == PackageManager.PERMISSION_GRANTED) {
            initMap()
        } else {
            ActivityCompat.requestPermissions(this,
                arrayOf(Manifest.permission.ACCESS_FINE_LOCATION),
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
            // Creating a marker
            val markerOptions = MarkerOptions()

            // Setting the position for the marker
            markerOptions.position(p0)

            // Setting the title for the marker.
            // This will be displayed on taping the marker
            markerOptions.title(p0.latitude.toString() + " : " + p0.longitude)

            // Clears the previously touched position
            mMap.clear()

            // Animating to the touched position
            mMap.animateCamera(CameraUpdateFactory.newLatLng(p0))

            // Placing a marker on the touched position
            mMap.addMarker(markerOptions)
        }
    }

    override fun onMyLocationButtonClick(): Boolean {
        Toast.makeText(this, "my location button click", Toast.LENGTH_LONG).show()
        return false
    }

    override fun onMyLocationClick(location: Location) {
        Toast.makeText(this, "my location click", Toast.LENGTH_LONG).show()
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
        initLocationTracking();
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
}
