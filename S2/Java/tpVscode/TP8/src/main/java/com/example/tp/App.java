package com.example.tp;

import java.lang.System.Logger;
import java.lang.System.Logger.Level;
import java.util.StringJoiner;

import com.example.tp.formes.Carre;
import com.example.tp.formes.Cercle;
import com.example.tp.formes.IForme;
import com.example.tp.formes.PileDeFormesTab;
import com.example.tp.formes.PileFormesBetter;

public class App {
    private static Logger logger = System.getLogger("null");

    public static void main(String[] args) {
        if (args.length == 3) {
            int n = Integer.parseInt(args[0]);
            int u0 = Integer.parseInt(args[1]);
            int u1 = Integer.parseInt(args[2]);
            try {
                logger.log(Level.INFO, suite(n, u0, u1));
            } catch (Exception e) {
                logger.log(Level.ERROR, e.toString());
            }
        } else {
            testPileFormes();
        }
    }

    public static boolean isEven(int x) {
        return x % 2 == 0;
    }

    public static int suite(int n, int u0, int u1) throws SuiteException {
        if (n > 1) {
            try {
                return isEven(n)
                        ? suite(n - 1, u0, u1) / suite(n - 2, u0, u1) - suite(n - 2, u0, u1) / suite(n - 1, u0, u1)
                        : suite(n - 2, u0, u1) / suite(n - 1, u0, u1) - suite(n - 1, u0, u1) / suite(n - 2, u0, u1);
            } catch (SuiteException se) {
                se.ajouterTrace("qui est appelée dans suite(" + n + ", " + u0 + ", " + u1 + ")");
                throw se;
            } catch (Exception e) {
                throw new SuiteException("division par 0", "dans suite(" + n + ", " + u0 + ", " + u1 + ")");
            }
        }
        if (n == 1)
            return u1;
        return u0;
    }

    public static class SuiteException extends Exception {
        private final transient StringJoiner trace;

        public void ajouterTrace(String trace) {
            this.trace.add(trace);
        }

        public SuiteException(String msg, String initTrace) {
            super(msg);
            trace = new StringJoiner("\n\t");
            trace.add(initTrace);
        }

        @Override
        public String toString() {
            return getClass() + ": " + getMessage() + "\n" + trace.toString();
        }
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
        PileDeFormesTab pileFormes = new PileFormesBetter(3);
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
        var pfb2 = new PileFormesBetter(pileFormes);
        logger.log(Level.INFO, pileFormes.equals(pfb2));

    }

    public static void compare(IForme f1, IForme f2) {
        String str = f1.getSurface() > f2.getSurface() ? " est plus grand" : " est plus petit";

        logger.log(Level.INFO, f1 + str + " que " + f2);
    }
}
