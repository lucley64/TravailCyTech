package com.example;

public class Rectangle {
    private Segment i;
    private Segment j;
    public Rectangle(Segment i, Segment j) {
        setI(i);
        setJ(j);
    }
    public Segment getI() {
        return i;
    }
    public void setI(Segment i) {
        this.i = i;
    }
    public Segment getJ() {
        return j;
    }
    public void setJ(Segment j) {
        this.j = j;
    }
    
}
