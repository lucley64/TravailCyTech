package com.example.tp;

import java.lang.System.Logger;
import java.lang.System.Logger.Level;
import com.example.tp.formes.*;

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
        Cercle ce3 = new Cercle(-12, 3, 26);
        PileFormes pileFormes = new PileFormesBetter(3);
        logger.log(Level.INFO, pileFormes);
        logger.log(Level.INFO, pileFormes.vide());
        pileFormes.empiler(ce2);
        logger.log(Level.INFO, pileFormes);
        pileFormes.empiler(ca1);
        pileFormes.empiler(ca2);
        pileFormes.empiler(ce1);
        pileFormes.empiler(ce3);
        logger.log(Level.INFO, pileFormes);
        pileFormes.trier();
        logger.log(Level.INFO, pileFormes);
        pileFormes.depiler();
        logger.log(Level.INFO, pileFormes);
    }

    public static void compare(IForme f1, IForme f2) {
        String str = f1.getSurface() > f2.getSurface() ? " est plus grand" : " est plus petit";

        logger.log(Level.INFO, f1 + str + " que " + f2);
    }
}