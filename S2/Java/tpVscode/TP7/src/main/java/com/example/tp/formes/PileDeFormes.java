package com.example.tp.formes;

import java.util.Arrays;
import java.util.StringJoiner;

public abstract class PileDeFormes implements PileFormes{
    protected IForme[] formes;
    protected int sommet;


    protected PileDeFormes(int taille) {
        formes = new IForme[taille];
        sommet = 0;
    }

    protected PileDeFormes(IForme[] formes, int taille) {
        this.formes = Arrays.copyOf(formes, taille > formes.length ? taille : formes.length);
        sommet = formes.length;
    }

    protected void ajouterComp(IForme f){
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

    @Override
    public void depiler() {
        formes[--sommet] = null;
    }

    @Override
    public IForme sommet() {
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
}