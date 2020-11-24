package com.example.androidarpresentation

import android.Manifest
import android.annotation.SuppressLint
import android.content.Intent
import android.content.pm.PackageManager
import android.media.Image
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.os.Handler
import android.provider.MediaStore
import android.util.Log
import android.view.MotionEvent
import android.view.View
import android.widget.ImageView
import android.widget.Toast
import androidx.core.app.ActivityCompat
import androidx.core.content.ContextCompat
import com.google.ar.core.Anchor
import com.google.ar.core.ArCoreApk
import com.google.ar.core.HitResult
import com.google.ar.core.Plane
import com.google.ar.core.exceptions.UnavailableUserDeclinedInstallationException
import com.google.ar.sceneform.AnchorNode
import com.google.ar.sceneform.rendering.ModelRenderable
import com.google.ar.sceneform.rendering.ViewRenderable
import com.google.ar.sceneform.ux.ArFragment
import kotlinx.android.synthetic.main.activity_main.*
import com.google.ar.sceneform.ux.TransformableNode
import java.util.concurrent.CompletableFuture

class MainActivity : AppCompatActivity() {

    var ENABLE_CAMERA: Int = 111;
    var viewRenderable: ViewRenderable? = null;
    var future: CompletableFuture<ViewRenderable>? = null;

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        future = ViewRenderable.builder()
            .setView(this, R.layout.text_view)
            .build()

        quit.setOnClickListener {
            finish()
        }
      
        checkPermissions()
        maybeEnableArButton()
        checkARInstall()
        initAR()
    }

    override fun onRequestPermissionsResult(
        requestCode: Int,
        permissions: Array<out String>,
        grantResults: IntArray
    ) {
        super.onRequestPermissionsResult(requestCode, permissions, grantResults)
        when (requestCode) {
            ENABLE_CAMERA -> {
                if((grantResults.isNotEmpty() && grantResults[0] == PackageManager.PERMISSION_GRANTED)){
                    Log.i("dhl", "Camera permission granted.");
                } else {
                    Log.i("dhl", "Camera permission rejected.");
                }
                return
            }

            else -> {
                // fall through.
            }
        }
    }

    fun checkPermissions() {
        if (ContextCompat.checkSelfPermission(this, Manifest.permission.CAMERA)
            != PackageManager.PERMISSION_GRANTED) {
            ActivityCompat.requestPermissions(this,
                arrayOf(Manifest.permission.CAMERA),
                ENABLE_CAMERA)
            // Grant permission and return
            return
        }
        // Permission has already been granted, fall through
        return
    }


    fun maybeEnableArButton() {
        val availability = ArCoreApk.getInstance().checkAvailability(this)
        if (availability.isTransient) {
            // Re-query at 5Hz while compatibility is checked in the background.
            Handler().postDelayed(Runnable { maybeEnableArButton() }, 200)
        }
        if (availability.isSupported) {
            Log.i("dhl", "AR supported.");
        } else { // Unsupported or unknown.
            Log.i("dhl", "AR not supported for the phone.");
        }
    }

    fun checkARInstall() {
        try {
            when (ArCoreApk.getInstance().requestInstall(this, true)) {
                ArCoreApk.InstallStatus.INSTALLED -> {

                }
            }
        } catch (e: UnavailableUserDeclinedInstallationException) {
            Toast.makeText(this, "TODO: handle exception " + e, Toast.LENGTH_LONG)
                .show();
            return;
        }
    }
      
    fun initAR() {

        var arFragment = getSupportFragmentManager()
            .findFragmentById(R.id.ux_fragment) as ArFragment
        arFragment.setOnTapArPlaneListener {
                hitResult: HitResult, plane: Plane, motionEvent: MotionEvent ->
            if(plane.getAnchors().isEmpty()) {
                future?.thenAccept{ renderable -> viewRenderable = renderable }

                // Create the Anchor.
                val anchor = hitResult.createAnchor()
                val anchorNode = AnchorNode(anchor)
                anchorNode.setParent(arFragment.arSceneView.scene)

                // Create the transformable ViewRederable and add it to the anchor.
                var tfNode: TransformableNode = TransformableNode(arFragment.getTransformationSystem());
                tfNode.setParent(anchorNode);
                tfNode.setRenderable(viewRenderable);
                tfNode.select();

                if (viewRenderable == null) {
                    return@setOnTapArPlaneListener
                }

            } else {
                var anchors: Collection<Anchor> = plane.anchors;

                for (anchor in anchors) {
                    anchor.detach();
                }

                return@setOnTapArPlaneListener

            }
        }
    }
}
