package com.example.tp;

import java.lang.System.Logger;
import java.lang.System.Logger.Level;

public class App {
    private static Logger logger = System.getLogger("null");

    public static void main(String[] args) {
        testPileFormes();
    }

    public static void testFormes() {
        Carre ca1 = new Carre(22, 12, 10);
        Carre ca2 = new Carre(50, 50, 50);
        Cercle ce1 = new Cercle(0, 0, 22);
        Cercle ce2 = new Cercle(-12, 3, 2);

        compare(ca1, ce2);
        compare(ce1, ce2);
        compare(ca1, ca2);

    }

    public static void testPileFormes() {
        Carre ca1 = new Carre(22, 12, 10);
        Carre ca2 = new Carre(50, 50, 50);
        Cercle ce1 = new Cercle(0, 0, 22);
        Cercle ce2 = new Cercle(-12, 3, 2);
        PileFormes pileFormes = new PileFormesBetter(3);
        logger.log(Level.INFO, pileFormes.vide());
        pileFormes.empiler(ce2);
        logger.log(Level.INFO, pileFormes);
        pileFormes.empiler(ce1);
        pileFormes.empiler(ca1);
        pileFormes.empiler(ca2);
        logger.log(Level.INFO, pileFormes);
        logger.log(Level.INFO, pileFormes.sommet());
        pileFormes.depiler();
        logger.log(Level.INFO, pileFormes);
    }

    public static void compare(Forme f1, Forme f2) {
        String str = f1.getSurface() > f2.getSurface() ? " est plus grand" : " est plus petit";

        logger.log(Level.INFO, f1 + str + " que " + f2);
    }
}