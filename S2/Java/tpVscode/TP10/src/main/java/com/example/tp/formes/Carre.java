package com.example.tp.formes;

public class Carre extends Forme{
    private int cote;

    public Carre(int x, int y, int cote){
        super(x, y, cote, cote);
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
    public void setLongueur(int longueur) {
        setCote(longueur);
    }

    @Override
    public void setLargeur(int largeur) {
        setCote(largeur);
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
        return "Carre [cote=" + cote + ", x=" + getX() + ", y=" + getY() + ", surface=" + getSurface() + "]";
    }
    
}