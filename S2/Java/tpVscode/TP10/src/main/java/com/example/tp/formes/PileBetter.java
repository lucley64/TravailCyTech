package com.example.tp.formes;

import java.util.Arrays;
/**
 * PileFormesBetter
 */
public class PileBetter<T extends Comparable<T>> extends PileTab<T> {

    public PileBetter(int taille) {
        super(taille);
    }

    public PileBetter(T[] formes, int taille) {
        super(formes, taille);
    }

    public PileBetter(PileTab<T> other){
        super(other);
    }

    private void extendSize() {
        formes = Arrays.copyOf(formes, formes.length * 2 + 1);
    }

    @Override
    public void empiler(T f) {
        if (sommet == formes.length)
            extendSize();
        formes[sommet++] = f;
    }


    @Override
    public void trier() {
        var pfb = new PileBetter<T>(sommet);
        while (!vide()) {
            var s = sommet();
            depiler();
            pfb.ajouterComp(s);
        }
        while (!pfb.vide()){
            empiler(pfb.sommet());
            pfb.depiler();
        }
    }

    @Override
    protected Object clone() throws CloneNotSupportedException {
        return new PileBetter<T>(this);
    }
}