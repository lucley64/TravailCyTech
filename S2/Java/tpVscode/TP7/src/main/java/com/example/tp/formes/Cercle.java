package com.example.tp.formes;

public class Cercle extends Forme {
    private int rayon;

    public Cercle(int x, int y, int rayon) {
        super(x, y, rayon, rayon);
    }

    @Override
    public int getLargeur() {
        return getRayon();
    }

    @Override
    public int getLongueur() {
        return getRayon();
    }

    public int getRayon() {
        return rayon;
    }

    @Override
    public double getSurface() {
        return Math.PI * Math.pow(getRayon(), 2);
    }

    @Override
    public void setLongueur(int longueur) {
        setRayon(longueur);
    }

    @Override
    public void setLargeur(int largeur) {
        setRayon(largeur);
    }

    public void setRayon(int rayon) {
        this.rayon = rayon;
    }

    @Override
    public String toString() {
        return "Cercle [rayon=" + rayon + ", x=" + getX() + ", y=" + getY() + ", surface=" + getSurface() + "]";
    }
}