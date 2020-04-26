package com.example.trydragdropswiperecyclerview

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import androidx.recyclerview.widget.LinearLayoutManager
import com.ernestoyaquello.dragdropswiperecyclerview.DragDropSwipeRecyclerView
import com.ernestoyaquello.dragdropswiperecyclerview.ScrollAwareRecyclerView
import com.ernestoyaquello.dragdropswiperecyclerview.listener.OnItemSwipeListener

class MainActivity : AppCompatActivity() {

    val dataSet = listOf("Item 1", "Item 2", "Item 3")
    private val onItemSwipeListener = object : OnItemSwipeListener<String> {
        override fun onItemSwiped(position: Int,
                                  direction: OnItemSwipeListener.SwipeDirection,
                                  item: String): Boolean {

            val item = dataSet[position]

            return false
        }
    }

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        var mAdapter = MyAdapter(dataSet)
        var mList: DragDropSwipeRecyclerView = findViewById(R.id.list)
        mList.orientation = DragDropSwipeRecyclerView.ListOrientation.VERTICAL_LIST_WITH_VERTICAL_DRAGGING
        mList.layoutManager = LinearLayoutManager(this)
        mList.adapter = mAdapter
        mList.swipeListener = onItemSwipeListener
    }
}