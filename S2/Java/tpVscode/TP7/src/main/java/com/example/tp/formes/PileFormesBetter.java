package com.example.tp.formes;

import java.util.Arrays;
/**
 * PileFormesBetter
 */
public class PileFormesBetter extends PileDeFormes {

    public PileFormesBetter(int taille) {
        super(taille);
    }

    public PileFormesBetter(IForme[] formes, int taille) {
        super(formes, taille);
    }

    private void extendSize() {
        formes = Arrays.copyOf(formes, formes.length * 2 + 1);
    }

    @Override
    public void empiler(IForme f) {
        if (sommet == formes.length)
            extendSize();
        formes[sommet++] = f;
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
}