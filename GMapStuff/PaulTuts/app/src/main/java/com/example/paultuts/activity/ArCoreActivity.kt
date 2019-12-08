package com.example.paultuts.activity

import android.content.Context
import android.content.DialogInterface
import android.content.Intent
import android.graphics.BitmapFactory
import android.os.Bundle
import android.util.Log
import android.view.MotionEvent
import android.view.View
import android.widget.*
import androidx.appcompat.app.AlertDialog
import androidx.appcompat.app.AppCompatActivity
import com.example.paultuts.R
import com.example.paultuts.database.FirebaseDatabaseManager
import com.example.paultuts.database.ResolveDialog
import com.example.paultuts.fragment.ArCoreFragment
import com.google.ar.core.Anchor
import com.google.ar.core.HitResult
import com.google.ar.core.Plane
import com.google.ar.sceneform.AnchorNode
import com.google.ar.sceneform.Scene
import com.google.ar.sceneform.rendering.ModelRenderable
import com.google.ar.sceneform.rendering.Renderable
import com.google.ar.sceneform.rendering.ViewRenderable
import com.google.ar.sceneform.ux.ArFragment
import com.google.ar.sceneform.ux.TransformableNode
import com.google.firebase.database.DataSnapshot
import kotlinx.android.synthetic.main.activity_arcore.*
import java.io.File
import java.io.IOException
import java.text.SimpleDateFormat
import java.util.*
import java.util.concurrent.CompletableFuture


class ArCoreActivity : AppCompatActivity() {

    // Declare a CloudAnchor and an AppAnchorState
    private var cloudAnchor: Anchor? = null
    private var appAnchorState = AppAnchorState.NONE

    private var arCoreFragment: ArCoreFragment? = null
    private var firebaseDatabaseManager: FirebaseDatabaseManager? = null

    private var siteName: String = "";
    private var siteDescription: String = "";
    private var siteCreationDate: String = "";

    var anchorHolder: Anchor? = null
    private lateinit var renderableHolder: ViewRenderable
    private lateinit var arFragment: ArFragment

    private enum class AppAnchorState {
        NONE,
        HOSTING,
        HOSTED,
        RESOLVING,
        RESOLVED
    }

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_arcore)

        arCoreFragment = supportFragmentManager.findFragmentById(R.id.sceneform_fragment) as ArCoreFragment?
        arCoreFragment?.planeDiscoveryController?.hide()
        arCoreFragment?.arSceneView?.scene?.addOnUpdateListener {
            Scene.OnUpdateListener { p0 -> updateAnchorIfNecessary() }
        }
        arCoreFragment?.arSceneView?.scene?.addOnUpdateListener { p0 -> updateAnchorIfNecessary() }
        firebaseDatabaseManager = FirebaseDatabaseManager(this)

        initListeners()
    }

    private fun initListeners() {
        clear_button.setOnClickListener {
            setCloudAnchor(null)
        }

        resolve_button.setOnClickListener(View.OnClickListener {
            ResolveDialog(
                this,
                object : ResolveDialog.PositiveButtonListener {
                    override fun onPositiveButtonClicked(dialogValue: String) {
                        resolveAnchor(dialogValue)
                    }
                },
                getString(R.string.resolve),
                View.VISIBLE,
                View.VISIBLE
            ).show()
        })


        arCoreFragment?.setOnTapArPlaneListener { hitResult: HitResult, plane: Plane, _: MotionEvent ->
            var viewGenerator = layoutInflater.inflate(R.layout.view_generator, null) as LinearLayout;
            AlertDialog.Builder(this)
                .setView(viewGenerator)
                .setPositiveButton("Create", DialogInterface.OnClickListener {dialog, which ->
                    Log.i("dhl", "\n\n\nARFragment was tapped.");
                    siteName =
                        viewGenerator.findViewById<EditText>(R.id.site_name)
                            .text.toString();
                    siteDescription =
                        viewGenerator.findViewById<EditText>(R.id.site_description)
                            .text.toString();
                    siteCreationDate =
                        viewGenerator.findViewById<EditText>(R.id.site_creation_date)
                            .text.toString();
                    renderObject(hitResult, true);
                })
                .setNegativeButton("Cancel", DialogInterface.OnClickListener {dialog, which ->
                    Log.i("dhl", "Negative button clicked.");
                })
                .create()
                .show();
            if (plane.type != Plane.Type.HORIZONTAL_UPWARD_FACING || appAnchorState != AppAnchorState.NONE) {}
        }
    }

    fun resolveAnchor(dialogValue: String) {
        val siteName = dialogValue
        firebaseDatabaseManager?.getCloudAnchorID(siteName, object :
            FirebaseDatabaseManager.CloudAnchorIdListener {
            override fun onCloudAnchorIdAvailable(snapshot: DataSnapshot?) {
                val resolvedAnchor = arCoreFragment?.arSceneView?.session?.
                    resolveCloudAnchor(snapshot?.child("id")?.value.toString())
                setCloudAnchor(resolvedAnchor)
                showMessage("Now Resolving Anchor...")
                arCoreFragment?.let { placeObject(it, cloudAnchor, false, snapshot) }
                appAnchorState = AppAnchorState.RESOLVING
            }
        })
    }

    fun showMessage(message: String) {
        Toast.makeText(this, message, Toast.LENGTH_LONG).show()
    }

    private fun setCloudAnchor(newAnchor: Anchor?) {
        if (cloudAnchor != null) {
            cloudAnchor?.detach()
        }

        cloudAnchor = newAnchor
        appAnchorState = AppAnchorState.NONE
    }

    @Synchronized
    private fun updateAnchorIfNecessary() {
        if (appAnchorState != AppAnchorState.HOSTING && appAnchorState != AppAnchorState.RESOLVING) {
            return
        }
        val cloudState = cloudAnchor?.cloudAnchorState
        cloudState?.let { it ->
            if (appAnchorState == AppAnchorState.HOSTING) {
                if (it.isError) {
                    Toast.makeText(this, "Error hosting anchor.. $it", Toast.LENGTH_LONG).show()

                    appAnchorState = AppAnchorState.NONE
                } else if (it == Anchor.CloudAnchorState.SUCCESS) {
                    firebaseDatabaseManager?.nextShortCode(object :
                        FirebaseDatabaseManager.ShortCodeListener {
                        override fun onShortCodeAvailable(shortCode: Int?) {
                            if (shortCode == null) {
                                showMessage("Could not get shortCode")
                                return
                            }
                            cloudAnchor?.let {
                                firebaseDatabaseManager?.storeUsingShortCode(
                                    it.cloudAnchorId,
                                    siteName,
                                    siteDescription,
                                    siteCreationDate
                                )
                            }
                            showMessageWitAnchorId("Anchor hosted with site name: " + siteName)
                        }

                    })
                    appAnchorState = AppAnchorState.HOSTED
                }
            } else if (appAnchorState == AppAnchorState.RESOLVING) {
                if (it.isError) {
                    Toast.makeText(this, "Error hosting anchor.. $it", Toast.LENGTH_LONG).show()

                    appAnchorState = AppAnchorState.NONE
                } else if (it == Anchor.CloudAnchorState.SUCCESS) {
                    Toast.makeText(this, "Anchor resolved successfully", Toast.LENGTH_LONG).show()
                    addNodeToScene(arFragment, anchorHolder, renderableHolder)
                    appAnchorState = AppAnchorState.RESOLVED
                }
            }
        }

    }

    private fun showMessageWitAnchorId(s: String) {
        ResolveDialog(
            this,
            object : ResolveDialog.PositiveButtonListener {
                override fun onPositiveButtonClicked(dialogValue: String) {
                    resolveAnchor(dialogValue)
                }
            },
            s,
            View.GONE,
            View.GONE
        ).show()
    }

    private fun placeObject(fragment: ArFragment, anchor: Anchor?, creating: Boolean, snapshot: DataSnapshot?) {
        if(creating) {
            var view: View?;
            view = layoutInflater.inflate(R.layout.location_layout, null);
            view.findViewById<TextView>(R.id.location_name).setText(siteName);
            view.findViewById<TextView>(R.id.location_description).setText(siteDescription);
            view.findViewById<TextView>(R.id.location_creation_date).setText(siteCreationDate);
            ViewRenderable.builder()
                .setView(fragment.context, view)
                .build()
                .thenAccept { renderable -> addNodeToScene(fragment, anchor, renderable) }
                .exceptionally { throwable ->
                    val builder = android.app.AlertDialog.Builder(this)
                    builder.setMessage(throwable.message)
                        .setTitle("Error!")
                    val dialog = builder.create()
                    dialog.show()
                    null
                }
        } else {
            var view: View?;
            arFragment = fragment
            anchorHolder = anchor
            view = layoutInflater.inflate(R.layout.location_layout, null);
            view.findViewById<TextView>(R.id.location_name)
                .setText(snapshot?.key.toString());
            view.findViewById<TextView>(R.id.location_description)
                .setText(snapshot?.child("siteDescription")?.value.toString());
            view.findViewById<TextView>(R.id.location_creation_date).
                setText(snapshot?.child("siteCreationDate")?.value.toString());
            ViewRenderable.builder()
                .setView(fragment.context, view)
                .build()
//                .thenAccept { renderable -> addNodeToScene(fragment, anchor, renderable) }
                .thenAccept { renderable -> renderableHolder = renderable }
                .exceptionally { throwable ->
                    val builder = android.app.AlertDialog.Builder(this)
                    builder.setMessage(throwable.message)
                        .setTitle("Error!")
                    val dialog = builder.create()
                    dialog.show()
                    null
                }
        }
    }

    private fun addNodeToScene(fragment: ArFragment, anchor: Anchor?, renderable: Renderable) {
        val anchorNode = AnchorNode(anchor)
        val node = TransformableNode(fragment.transformationSystem)
        node.setParent(anchorNode)
        node.renderable = renderable;
        fragment.arSceneView.scene.addChild(anchorNode)
        node.select()
    }

    private fun renderObject(hitResult: HitResult, creating: Boolean) {
        var userInputView = layoutInflater.inflate(R.layout.user_input, null) as LinearLayout;
        AlertDialog.Builder(this)
            .setView(userInputView)
            .setPositiveButton("Add", DialogInterface.OnClickListener { dialog, which ->
                val newAnchor = arCoreFragment?.arSceneView?.session?.hostCloudAnchor(hitResult.createAnchor())
                setCloudAnchor(newAnchor)
                appAnchorState = AppAnchorState.HOSTING
                Toast.makeText(this, "Now hosting anchor...", Toast.LENGTH_LONG).show()
                arCoreFragment?.let { placeObject(it, cloudAnchor, creating, null) }
            })
            .setNegativeButton("Cancel", null)
            .create()
            .show();
    }
}