package com.example.tp.points;

public class Point3D extends Point2D {
    private double z;

    public Point3D(double abscisse, double ordonnee, double z) {
        super(abscisse, ordonnee);
        setZ(z);
    }

    public double getZ() {
        return z;
    }

    public void setZ(double z) {
        this.z = z;
    }

    @Override
    public int hashCode() {
        final int prime = 31;
        int result = super.hashCode();
        long temp;
        temp = Double.doubleToLongBits(z);
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
        Point3D other = (Point3D) obj;
        return Double.doubleToLongBits(z) == Double.doubleToLongBits(other.z);
    }

    @Override
    public String toString() {
        return "Point3D [abscisse=" + getAbscisse() + ", ordonnee=" + getOrdonnee() + ", z=" + getZ() + "]";
    }

}