package com.example.tp6

import android.content.Context
import android.graphics.Bitmap
import android.graphics.Canvas
import android.graphics.Color
import android.graphics.Paint
import android.hardware.Sensor
import android.hardware.SensorEvent
import android.hardware.SensorEventListener
import android.hardware.SensorManager
import android.util.AttributeSet
import android.view.MotionEvent
import android.view.SurfaceHolder
import android.view.SurfaceView
import kotlinx.coroutines.CoroutineScope
import kotlinx.coroutines.Dispatchers
import kotlinx.coroutines.Job
import kotlinx.coroutines.delay
import kotlinx.coroutines.launch
import java.util.concurrent.locks.ReentrantLock
import kotlin.random.Random

class BallGame(context: Context, attrs: AttributeSet? = null) : SurfaceView(context, attrs),
    SensorEventListener {
    private val paint = Paint()
    private var gameLoopJob: Job? = null
    private val surfaceHolder: SurfaceHolder = holder
    private val sensorManager: SensorManager =
        context.getSystemService(Context.SENSOR_SERVICE) as SensorManager
    private val accelerometer = sensorManager.getDefaultSensor(Sensor.TYPE_ACCELEROMETER)
    private val balls = mutableListOf<Ball>()
    private val ballsLock = ReentrantLock()
    private var backgroundBitmap: Bitmap? = null
    private var width = context.resources.displayMetrics.widthPixels.toFloat()
    private var height = context.resources.displayMetrics.heightPixels.toFloat()
    private var sensorX = 0f
    private var sensorY = 0f

    @Volatile
    private var paused = true

    init {
        setOnTouchListener { _, event ->
            val action = event.action
            if (action == MotionEvent.ACTION_DOWN) {
                val x = event.x
                val y = event.y
                ballsLock.lock()
                try {
                    balls.add(createBall(x, y))
                } finally {
                    ballsLock.unlock()
                }
            }
            true
        }
        repeat(4) { balls.add(createBall()) }
        backgroundBitmap =
            Bitmap.createBitmap(width.toInt(), height.toInt(), Bitmap.Config.ARGB_8888)
        val canvas = Canvas(backgroundBitmap!!)
        canvas.drawColor(Color.WHITE)
    }

    private fun createBall(): Ball {
        val random = Random
        val radius = 10f + random.nextFloat() * 49f
        val color = Color.argb(255, random.nextInt(256), random.nextInt(256), random.nextInt(256))
        val posX = radius + random.nextFloat() * (width - radius)
        val posY = radius + random.nextFloat() * (height - radius)
        return Ball(posX, posY, radius, color, width, height)
    }

    private fun createBall(x: Float, y: Float): Ball {
        val random = Random
        val radius = 10f + random.nextFloat() * 49f
        val color = Color.argb(255, random.nextInt(256), random.nextInt(256), random.nextInt(256))
        return Ball(x, y, radius, color, width, height)
    }


    private fun run() {
        while (!paused) {
            if (surfaceHolder.surface.isValid) {
                val canvas = surfaceHolder.lockCanvas()

                paint.isAntiAlias = true
                paint.style = Paint.Style.FILL

                canvas.drawBitmap(backgroundBitmap!!, 0f, 0f, paint)

                ballsLock.lock()
                try {
                    balls.forEach {
                        it.move(sensorX, sensorY)
                        it.draw(canvas)
                    }
                } finally {
                    ballsLock.unlock()
                }

                surfaceHolder.unlockCanvasAndPost(canvas)
            }
        }

    }

    fun resume() {
        paused = false
        gameLoopJob = CoroutineScope(
            Dispatchers.Default
        ).launch { run() }

        sensorManager.registerListener(this, accelerometer, SensorManager.SENSOR_DELAY_NORMAL)
    }

    fun pause() {
        paused = true
        gameLoopJob?.cancel()
        gameLoopJob = null

        sensorManager.unregisterListener(this)
    }

    override fun onSensorChanged(event: SensorEvent?) {
        event?.values?.let { values ->
            ballsLock.lock()
            try {
                sensorX = -values[0]
                sensorY = values[1]
            } finally {
                ballsLock.unlock()
            }
        }
    }

    override fun onAccuracyChanged(sensor: Sensor?, accuracy: Int) {
        // Not used
    }

    override fun onSizeChanged(w: Int, h: Int, oldw: Int, oldh: Int) {
        super.onSizeChanged(w, h, oldw, oldh)
        width = w.toFloat()
        height = h.toFloat()
        backgroundBitmap =
            Bitmap.createBitmap(width.toInt(), height.toInt(), Bitmap.Config.ARGB_8888)
        val canvas = Canvas(backgroundBitmap!!)
        canvas.drawColor(Color.WHITE)
        ballsLock.lock()
        try {
            balls.forEach { ball ->
                ball.maxY = height
                ball.maxX = width
            }
        } finally {
            ballsLock.unlock()
        }
    }

}