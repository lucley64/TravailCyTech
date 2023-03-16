package com.example.tp;

import java.lang.System.Logger.Level;

public class Point {
    private double r;
    private double theta;
    private double x;
    private double y;

    public Point() {
        this(0, 0);
    }

    public Point(double x, double y) {
        this.x = x;
        this.y = y;
        transform();
    }

    public double getX() {
        return Math.cos(theta) * r;
    }

    public void setX(double x) {
        this.x = x;
        transform();
    }

    public double getY() {
        return (Math.cos(-theta)) * r;
    }

    public void setY(double y) {
        this.y = y;
        transform();
    }

    private void transform(){
        r = Math.sqrt(Math.pow(x, 2) + Math.pow(y, 2));
        theta = (r == 0) ? 0 : Math.acos(x / r);
    }

    @Override
    public String toString() {
        return "(" + r + ", " + theta + ")";
    }

    @Override
    public boolean equals(Object obj) {
        if (obj instanceof Point) {
            var p = (Point) obj;
            return p.r == r && p.theta == theta;
        }
        return false;
    }

    @Override
    public int hashCode() {
        return (int) (getX() * getY());
    }

    public double distance(Point p) {
        return (Math.abs(getX() - p.getX()) * Math.abs(getY() - p.getY())) / 2;
    }

    public void translater(Point p) {
        setX(getX() + p.getX());
        setY(getY() + p.getY());
    }

    public static void main(String[] args) {
        var p1 = new Point();
        var p2 = new Point(10, 10);

        var logger = System.getLogger("mainLogger");

        logger.log(Level.INFO, "Distance entre p1 et p2 : " + p1.distance(p2));
        
        p1.translater(p2);
        logger.log(Level.INFO, "p2 : " + p2.getX() + ", " + p2.getY());
        logger.log(Level.INFO, "p1 : " + p1.getX() + ", " + p1.getY());

        logger.log(Level.INFO, "p1.equals(p2) ? " + p1.equals(p2) + "\n\t p1 == p2 ? " + (p1 == p2));

        var p3 = p1;

        p3.setX(12);

        logger.log(Level.INFO, "p1 = " + p1 + ", p2 = " + p2 + ", p3 = " + p3);
    }
}
