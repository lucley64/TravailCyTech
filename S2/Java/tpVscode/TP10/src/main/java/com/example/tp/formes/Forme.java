package com.example.tp.formes;

public abstract class Forme implements IForme {
    protected Point hg;
    protected Point centreGravite;

    protected Forme(int x, int y, int longueur, int largeur) {
        hg = new Point();
        setX(x);
        setY(y);
        setLongueur(longueur);
        setLargeur(largeur);
        calcCentreGrav();
    }
    
    @Override
    public int getX() {
        return hg.getX();
    }
    
    @Override
    public int getY() {
        return hg.getY();
    }

    @Override
    public void setX(int x) {
        hg.setX(x);
    }
    
    @Override
    public void setY(int y) {
        hg.setY(y);
    }

    public Point getCentreGrav(){
        return centreGravite;
    }
    
    private void calcCentreGrav(){
        centreGravite = new Point();
        centreGravite.setX(getX() + getLongueur() / 2);
        centreGravite.setY(getY() + getLargeur() / 2);
    }

    public void translater(int x1, int y1, int x2, int y2){
        setX(x2 - x1);
        setY(y2 - y1);
        calcCentreGrav();
    }



    protected class Point {
        protected int x;
        protected int y;

        public int getX() {
            return x;
        }

        public int getY() {
            return y;
        }

        public void setX(int x) {
            this.x = x;
        }

        public void setY(int y) {
            this.y = y;
        }
    }
}