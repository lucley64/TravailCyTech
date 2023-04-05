package com.example.tp.formes;

public class PileAvecTableauTailleFixe<T extends Comparable<T>> extends PileTab<T> {
    public PileAvecTableauTailleFixe(int taille) {
        super(taille);
    }

    public PileAvecTableauTailleFixe(T[] formes, int taille) {
        super(formes, taille);
    }

    public PileAvecTableauTailleFixe(PileTab<T> other){
        super(other);
    }

    @Override
    public void empiler(T f) {
        if (sommet == formes.length)
            throw new IndexOutOfBoundsException();

        formes[sommet++] = f;
    }

    @Override
    public void trier() {
        var pfb = new PileAvecTableauTailleFixe<T>(formes.length);
        while (!vide()) {
            var s = sommet();
            depiler();
            pfb.ajouterComp(s);
        }
        while (!pfb.vide()) {
            empiler(pfb.sommet());
            pfb.depiler();
        }
    }

    @Override
    protected Object clone() throws CloneNotSupportedException {
        super.clone();
        return new PileAvecTableauTailleFixe<T>(this);
    }
}