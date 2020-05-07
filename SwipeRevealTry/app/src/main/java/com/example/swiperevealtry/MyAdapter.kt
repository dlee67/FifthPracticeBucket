package com.example.swiperevealtry

import android.os.Bundle
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.widget.TextView
import android.widget.Toast
import androidx.recyclerview.widget.RecyclerView
import com.chauthai.swipereveallayout.SwipeRevealLayout
import com.chauthai.swipereveallayout.ViewBinderHelper
import org.w3c.dom.Text

class MyAdapter(private val myDataset: Array<String>) :
    RecyclerView.Adapter<MyAdapter.MyViewHolder>() {

    private val binderHelper = ViewBinderHelper()

    class MyViewHolder(val textView: View) : RecyclerView.ViewHolder(textView) {

        lateinit var swipeLayout: SwipeRevealLayout;
        lateinit var frontLayout: View;
        lateinit var deleteLayout: View;
        lateinit var text: TextView;

        init {
            swipeLayout = textView.findViewById(R.id.swipe_layout)
            frontLayout = textView.findViewById(R.id.front_layout);
            deleteLayout = textView.findViewById(R.id.delete_layout)
            text = textView.findViewById(R.id.text)
        }

        fun bind(data: String) {
            deleteLayout.setOnClickListener {
            }
            text.text = data;
            frontLayout.setOnClickListener {
            }
        }
    }

    override fun onCreateViewHolder(parent: ViewGroup,
                                    viewType: Int): MyAdapter.MyViewHolder {
        val textView = LayoutInflater.from(parent.context)
            .inflate(R.layout.my_text_view, parent, false)
        return MyViewHolder(textView)
    }

    override fun onBindViewHolder(holder: MyViewHolder, position: Int) {
        binderHelper.bind(holder.swipeLayout, myDataset[position])
        holder.bind(myDataset[position])
    }

    override fun getItemCount() = myDataset.size

    fun saveStates(outState: Bundle) {
        binderHelper.saveStates(outState)
    }

    fun restoreStates(inState: Bundle){
         binderHelper.restoreStates(inState)
    }
}