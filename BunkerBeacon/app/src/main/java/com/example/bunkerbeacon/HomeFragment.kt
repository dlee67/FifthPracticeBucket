package com.example.bunkerbeacon

import android.app.AlarmManager
import android.app.NotificationChannel
import android.app.NotificationManager
import android.app.PendingIntent
import android.content.Context.ALARM_SERVICE
import android.content.Context.NOTIFICATION_SERVICE
import android.content.Intent
import android.graphics.Color
import android.os.Build
import android.os.Bundle
import android.os.SystemClock
import android.util.Log
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.widget.Button
import android.widget.EditText
import android.widget.Toast
import androidx.fragment.app.Fragment
import java.util.concurrent.TimeUnit

// TODO: Rename parameter arguments, choose names that match
// the fragment initialization parameters, e.g. ARG_ITEM_NUMBER
private const val ARG_PARAM1 = "param1"
private const val ARG_PARAM2 = "param2"

/**
 * A simple [Fragment] subclass.
 * Use the [HomeFragment.newInstance] factory method to
 * create an instance of this fragment.
 */
class HomeFragment : Fragment() {
    // TODO: Rename and change types of parameters
    private var param1: String? = null
    private var param2: String? = null

    val NOTIFICATION_ID = 0
    val PRIMARY_CHANNEL_ID = "primary_notification_channel"

    lateinit var notificationManager: NotificationManager
    lateinit var firstNumberView: EditText
    lateinit var secondNumberView: EditText

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        arguments?.let {
            param1 = it.getString(ARG_PARAM1)
            param2 = it.getString(ARG_PARAM2)
        }
    }

    override fun onCreateView(inflater: LayoutInflater, container: ViewGroup?,
                              savedInstanceState: Bundle?): View? {
        val homeFragment = inflater.inflate(R.layout.fragment_home, container, false)

        notificationManager = context?.getSystemService(NOTIFICATION_SERVICE) as NotificationManager

        var alarmManager = context?.getSystemService(ALARM_SERVICE) as AlarmManager
        firstNumberView = homeFragment.findViewById(R.id.first_phone_number)
        secondNumberView = homeFragment.findViewById(R.id.second_phone_number)

        homeFragment.findViewById<Button>(R.id.sendButton).setOnClickListener {
            Log.i("dhl", "Sending message")

            var firstNumber = firstNumberView.text
            var secondNumber = secondNumberView.text
            Log.i("dhl", "first number at: " + firstNumber)
            var notifyIntent = Intent(context, AlarmReceiver::class.java)
            notifyIntent.putExtra("firstNumber", firstNumber.toString())
            notifyIntent.putExtra("secondNumber", secondNumber.toString())
            var pendingIntent = PendingIntent.getBroadcast(context, NOTIFICATION_ID, notifyIntent,
                    PendingIntent.FLAG_UPDATE_CURRENT)
            var amountOfDays = Integer(homeFragment.findViewById<EditText>(R.id.second_phone_number)
                    .text.toString());

            var waitInterval = TimeUnit.DAYS.toMillis(amountOfDays.toLong());

            if (alarmManager != null) {
                alarmManager?.setExactAndAllowWhileIdle(
                        AlarmManager.ELAPSED_REALTIME_WAKEUP,
                        // elapsedRealtime() is required to actually the correct amount of pass.
                        SystemClock.elapsedRealtime() + waitInterval,
                        pendingIntent)
            }

            Toast.makeText(context, "Test set", Toast.LENGTH_SHORT).show();
        }
        createNotificationChannel()

        // Inflate the layout for this fragment
        return homeFragment
    }

    fun createNotificationChannel() {
        notificationManager = context?.getSystemService(NOTIFICATION_SERVICE) as NotificationManager

        if (Build.VERSION.SDK_INT >=
                Build.VERSION_CODES.O) {

            // Create the NotificationChannel with all the parameters.
            val notificationChannel = NotificationChannel(PRIMARY_CHANNEL_ID,
                    "Stand up notification",
                    NotificationManager.IMPORTANCE_HIGH)
            notificationChannel.enableLights(true)
            notificationChannel.lightColor = Color.RED
            notificationChannel.enableVibration(true)
            notificationChannel.description = "Notification test description"
            notificationManager.createNotificationChannel(notificationChannel)
        }
    }

    companion object {
        /**
         * Use this factory method to create a new instance of
         * this fragment using the provided parameters.
         *
         * @param param1 Parameter 1.
         * @param param2 Parameter 2.
         * @return A new instance of fragment HomeFragment.
         */
        // TODO: Rename and change types and number of parameters
        @JvmStatic
        fun newInstance(param1: String, param2: String) =
                HomeFragment().apply {
                    arguments = Bundle().apply {
                        putString(ARG_PARAM1, param1)
                        putString(ARG_PARAM2, param2)
                    }
                }
    }
}