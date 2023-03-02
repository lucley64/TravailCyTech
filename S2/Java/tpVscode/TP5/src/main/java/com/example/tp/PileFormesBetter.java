package com.example.tp;

import java.util.Arrays;
import java.util.StringJoiner;

/**
 * PileFormesBetter
 */
public class PileFormesBetter implements PileFormes {
    private Forme[] formes;
    private int sommet;

    public PileFormesBetter(int taille) {
        formes = new Forme[taille];
        sommet = 0;
    }

    public PileFormesBetter(Forme[] formes, int taille) {
        this.formes = Arrays.copyOf(formes, taille > formes.length ? taille : formes.length);
        sommet = formes.length;
    }

    private void extendSize() {
        formes = Arrays.copyOf(formes, formes.length * 2 + 1);
    }

    @Override
    public void empiler(Forme f) {
        if (sommet == formes.length)
            extendSize();
        formes[sommet++] = f;
    }

    @Override
    public void depiler() {
        formes[--sommet] = null;
    }

    @Override
    public Forme sommet() {
        if (vide())
            throw new IndexOutOfBoundsException();
        return formes[sommet - 1];
    }

    @Override
    public boolean vide() {
        return sommet == 0;
    }

    @Override
    public String toString() {
        var s = new StringJoiner(", ");
        for (var i = 0; i < sommet; i++) {
            s.add(formes[i].toString());
        }
        return "[ " + s + " ]";
    }

    @Override
    public void trier() {
        var pfb = new PileFormesBetter(sommet);
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
    
    private void ajouterComp(Forme f){
        if(!vide()) {
            var s2 = sommet();
            if (s2.getSurface() < f.getSurface()) {
                empiler(f);
            } else {
                depiler();
                ajouterComp(f);
                empiler(s2);
            }
        } else {
            empiler(f);
        }
    }
}