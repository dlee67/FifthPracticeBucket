package com.example.bunkerbeacon

import android.app.NotificationManager
import android.app.PendingIntent
import android.content.BroadcastReceiver
import android.content.Context
import android.content.Intent
import android.telephony.SmsManager
import android.util.Log
import androidx.core.app.NotificationCompat

class AlarmReceiver: BroadcastReceiver() {

    lateinit var notificationManager: NotificationManager

    val NOTIFICATION_ID = 0
    val PRIMARY_CHANNEL_ID = "primary_notification_channel"

    override fun onReceive(context: Context?, intent: Intent?) {
        notificationManager = context?.getSystemService(Context.NOTIFICATION_SERVICE)
                as NotificationManager
          val phoneNumber = intent?.extras?.getString("firstNumber")
          Log.i("dhl", "In the receiver, phone number at: " + phoneNumber)
          val message = "Panic"
          val smsManager: SmsManager = SmsManager.getDefault()
          smsManager.sendTextMessage(phoneNumber,
                  null, message, null, null)
        deliverNotification(context)
    }

    fun deliverNotification(context: Context?) {
        if (context != null) {
            val contentIntent = Intent(context, MainActivity::class.java)
            val contentPendingIntent = PendingIntent.getActivity(context,
                    NOTIFICATION_ID, contentIntent, PendingIntent.FLAG_UPDATE_CURRENT)
            val builder = NotificationCompat.Builder(context, PRIMARY_CHANNEL_ID)
                .setSmallIcon(R.drawable.ic_launcher_foreground)
                .setContentTitle("No more cry boy")
                .setContentText("because I am beside you")
                .setContentIntent(contentPendingIntent)
                .setPriority(NotificationCompat.PRIORITY_HIGH)
                .setAutoCancel(true)
                .setDefaults(NotificationCompat.DEFAULT_ALL)
            notificationManager.notify(NOTIFICATION_ID, builder.build());
        }
    }
}