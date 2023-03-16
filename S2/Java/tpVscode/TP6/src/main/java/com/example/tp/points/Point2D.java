package com.example.tp.points;

public class Point2D extends Point1D{
    

    private double ordonnee;

    public Point2D(double abscisse, double ordonnee) {
        super(abscisse);
        setOrdonnee(ordonnee);
    }

    public double getOrdonnee() {
        return ordonnee;
    }

    public void setOrdonnee(double ordonnee) {
        this.ordonnee = ordonnee;
    }

    @Override
    public String toString() {
        return "Point2D [abscisse=" + getAbscisse() + ", ordonnee=" + getOrdonnee() + "]";
    }

    @Override
    public int hashCode() {
        final int prime = 31;
        int result = super.hashCode();
        long temp;
        temp = Double.doubleToLongBits(ordonnee);
        result = prime * result + (int) (temp ^ (temp >>> 32));
        return result;
    }

    @Override
    public boolean equals(Object obj) {
        if (this == obj)
            return true;
        if (!super.equals(obj))
            return false;
        if (getClass() != obj.getClass())
            return false;
        Point2D other = (Point2D) obj;
        return (Double.doubleToLongBits(ordonnee) == Double.doubleToLongBits(other.ordonnee));
    }

    
}