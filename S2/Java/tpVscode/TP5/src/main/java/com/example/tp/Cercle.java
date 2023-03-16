package com.example.tp;

public class Cercle implements Forme {
    private int rayon;
    private int x;
    private int y;

    public Cercle(int x, int y, int rayon) {
        setRayon(rayon);
        setX(x);
        setY(y);
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
    public int getX() {
        return x;
    }

    @Override
    public int getY() {
        return y;
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
    public void setX(int x) {
        this.x = x;
    }

    @Override
    public void setY(int y) {
        this.y = y;
    }

    @Override
    public String toString() {
        return "Cercle [rayon=" + rayon + ", x=" + x + ", y=" + y + ", surface=" + getSurface() + "]";
    }
}