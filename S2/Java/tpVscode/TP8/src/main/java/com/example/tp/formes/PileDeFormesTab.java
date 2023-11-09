package com.example.tp.formes;

import java.util.Arrays;

public abstract class PileDeFormesTab extends PileDeFormes {
    protected IForme[] formes;

    public IForme[] getFormes() {
        return formes;
    }

    protected int sommet;

    protected PileDeFormesTab(int taille) {
        formes = new IForme[taille];
        sommet = 0;
    }

    protected PileDeFormesTab(IForme[] formes, int taille) {
        this.formes = Arrays.copyOf(formes, taille > formes.length ? taille : formes.length);
        sommet = taille;
    }

    protected PileDeFormesTab(PileDeFormesTab formes) {
        this(formes.getFormes(), formes.taille());
    }

    protected void ajouterComp(IForme f) {
        if (!vide()) {
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
        if (vide())
            throw new IndexOutOfBoundsException();
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
    public int taille() {
        return sommet;
    }

    @Override
    public int hashCode() {
        final int prime = 31;
        int result = 1;
        result = prime * result + Arrays.hashCode(formes);
        result = prime * result + sommet;
        return result;
    }

    @Override
    public boolean equals(Object obj) {
        return super.equals(obj);
    }

}