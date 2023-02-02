package com.example.tp;

import java.lang.System.Logger.Level;

public class Point {
    private int x;
    private int y;

    public Point() {
        this(0, 0);
    }

    public Point(int x, int y) {
        setX(x);
        setY(y);
    }

    public int getX() {
        return x;
    }

    public void setX(int x) {
        this.x = x;
    }

    public int getY() {
        return y;
    }

    public void setY(int y) {
        this.y = y;
    }

    @Override
    public String toString() {
        return "(" + x + ", " + y + ")";
    }

    @Override
    public boolean equals(Object obj) {
        if (obj instanceof Point){
            var p = (Point) obj;
            return p.x == x && p.y == y;
        }
        return false;
    }

    @Override
    public int hashCode() {
        return x * y;
    }

    public int distance(Point p){
        return (Math.abs(x - p.x) * Math.abs(y - p.y)) / 2 ;
    }

    public void translater(Point p){
        setX(x + p.x);
        setY(y + p.y);
    }


    public static void main(String[] args) {
        var p1 = new Point();
        var p2 = new Point(10, 10);

        var logger = System.getLogger("mainLogger");

        logger.log(Level.INFO, "Distance entre p1 et p2 : " + p1.distance(p2));

        p1.translater(p2);

        logger.log(Level.INFO, "p1.equals(p2) ? " + p1.equals(p2) + "\n\t p1 == p2 ? " + (p1 == p2));

        var p3 = p1;

        p3.setX(12);

        logger.log(Level.INFO, "p1 = " + p1 + ", p2 = " + p2 + ", p3 = " + p3);
    }
}
