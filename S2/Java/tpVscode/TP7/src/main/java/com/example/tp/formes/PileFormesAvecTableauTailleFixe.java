package com.example.tp.formes;

public class PileFormesAvecTableauTailleFixe extends PileDeFormes {
    public PileFormesAvecTableauTailleFixe(int taille) {
        super(taille);
    }

    public PileFormesAvecTableauTailleFixe(IForme[] formes, int taille) {
        super(formes, taille);
    }

    @Override
    public void empiler(IForme f) {
        if (sommet != formes.length)
            formes[sommet++] = f;
    }

    @Override
    public void trier() {
        var pfb = new PileFormesAvecTableauTailleFixe(formes.length);
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