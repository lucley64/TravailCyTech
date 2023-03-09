package com.example.tp;

import java.lang.System.Logger;
import java.lang.System.Logger.Level;

import com.example.tp.points.Point1D;
import com.example.tp.points.Point2D;
import com.example.tp.points.Point3D;

public class App {
    private static Logger logger = System.getLogger("null");

    public static void main(String[] args) {
        Point1D[] points = { new Point1D(12), new Point1D(25), new Point2D(0, 0), new Point3D(0, 0, 0) };
        Point1D p1 = new Point2D(42, 12);

        logger.log(Level.INFO, p1.afficherEgaux(points));
    }
}