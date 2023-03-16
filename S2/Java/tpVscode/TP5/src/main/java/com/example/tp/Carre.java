package com.example.tp;

public class Carre implements Forme{
    private int cote;
    private int x;
    private int y;

    public Carre(int x, int y, int cote){
        setX(x);
        setY(y);
        setCote(cote);
    }

    @Override
    public int getLongueur() {
        return getCote();
    }

    @Override
    public int getLargeur() {
        return getCote();
    }

    public int getCote() {
        return cote;
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
        setCote(longueur);
    }

    @Override
    public void setLargeur(int largeur) {
        setCote(largeur);
    }

    @Override
    public void setX(int x) {
        this.x = x;
    }

    @Override
    public void setY(int y) {
        this.y = y;
    }

    public void setCote(int cote) {
        this.cote = cote;
    }

    @Override
    public double getSurface() {
        return Math.pow(getCote(), 2);
    }

    @Override
    public String toString() {
        return "Carre [cote=" + cote + ", x=" + x + ", y=" + y + ", surface=" + getSurface() + "]";
    }
    
}