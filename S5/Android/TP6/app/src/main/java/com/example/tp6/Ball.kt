package com.example.tp6

import android.graphics.Canvas
import android.graphics.Paint

class Ball(
    private var positionX: Float,
    private var positionY: Float,
    private val radius: Float,
    private val color: Int,
    var maxX: Float,
    var maxY: Float
) {

    fun draw(canvas: Canvas) {
        val paint = Paint(Paint.ANTI_ALIAS_FLAG)
        paint.color = color
        canvas.drawCircle(positionX, positionY, radius, paint)
    }

    fun move(dx: Float, dy: Float) {
        val newX = positionX + dx
        val newY = positionY + dy
        positionX = if (newX + radius < maxX) {
            if (newX - radius > 0) {
                newX
            } else {
                0f + radius
            }
        } else {
            maxX - radius
        }
        positionY = if (newY + radius < maxY) {
            if (newY - radius > 0) {
                newY
            } else {
                0f + radius
            }
        } else {
            maxY - radius
        }
    }
}