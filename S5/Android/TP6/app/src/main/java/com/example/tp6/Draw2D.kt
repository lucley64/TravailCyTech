package com.example.tp6

import android.content.Context
import android.graphics.Canvas
import android.graphics.Color
import android.graphics.Paint
import android.util.AttributeSet
import android.view.View

class Draw2D(context: Context?, attrs: AttributeSet?) : View(context, attrs) {
    private val paint = Paint()

    override fun onDraw(canvas: Canvas) {
        super.onDraw(canvas)

        // Initialisation
        paint.isAntiAlias = true
        paint.style = Paint.Style.FILL

        // Background
        paint.color = Color.RED
        canvas.drawPaint(paint)

        // Circle
        paint.color = Color.BLUE
        canvas.drawCircle(canvas.width / 2f, canvas.height / 2f, 50f, paint)
    }
}