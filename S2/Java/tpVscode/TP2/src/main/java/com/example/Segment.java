package com.example;

public class Segment {
    private Point a;
    private Point b;
    public Segment(Point a, Point b) {
        setA(a);
        setB(b);
    }
    public Point getA() {
        return a;
    }
    public void setA(Point a) {
        this.a = a;
    }
    public Point getB() {
        return b;
    }
    public void setB(Point b) {
        this.b = b;
    }
}
