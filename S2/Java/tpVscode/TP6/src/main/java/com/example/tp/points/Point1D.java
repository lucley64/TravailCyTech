package com.example.tp.points;

import java.util.StringJoiner;

public class Point1D {
    private double abscisse;

    public Point1D(double abscisse) {
        setAbscisse(abscisse);
    }

    public double getAbscisse() {
        return abscisse;
    }

    public void setAbscisse(double abscisse) {
        this.abscisse = abscisse;
    }

    @Override
    public String toString() {
        return "Point1D [abscisse=" + getAbscisse() + "]";
    }

    @Override
    public int hashCode() {
        final int prime = 31;
        int result = 1;
        long temp;
        temp = Double.doubleToLongBits(abscisse);
        result = prime * result + (int) (temp ^ (temp >>> 32));
        return result;
    }

    @Override
    public boolean equals(Object obj) {
        if (this == obj)
            return true;
        if (obj == null)
            return false;
        if (getClass() != obj.getClass())
            return false;
        Point1D other = (Point1D) obj;
        return Double.doubleToLongBits(abscisse) == Double.doubleToLongBits(other.abscisse);
    }


    public String afficherEgaux(Point1D[] points){
        var sj = new StringJoiner("\n");
        for (var p1 : points) {
            if (equals(p1)) {
                sj.add(p1.toString());
            }
        }
        return sj.toString();
    }

    
}