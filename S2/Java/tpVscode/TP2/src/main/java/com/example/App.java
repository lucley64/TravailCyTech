package com.example;

import java.lang.System.Logger;
import java.lang.System.Logger.Level;
import java.time.LocalDate;
import java.util.Random;
import java.util.StringJoiner;
import java.util.regex.Pattern;

/**
 * Classe principale de l'application
 * 
 * @author me
 * @version 1.0
 */
public class App {

    /**
     * Logger utilisé pour print
     */
    private static Logger logger = System.getLogger("mainLogger");

    /**
     * Métode main
     * 
     * @param args Array des arguments
     */
    public static void main(String[] args) {
        logger.log(Level.INFO, "Hello, World!");

        int x;
        int y;
        int z;

        var rand = new Random();

        x = rand.nextInt(30);
        y = rand.nextInt(30);
        z = rand.nextInt(30);

        logger.log(Level.INFO, "x: " + x + ", y: " + y + ", z: " + z);
        logger.log(Level.INFO,
                "1. x et y sont toutes deux strictement sup érieures à 3 : (x > 3 && y > 3) = "
                        + (x > 3 && y > 3));
        logger.log(Level.INFO, "2. x, y et z ont la même valeur : (x == y && x == z) = " + (x == y && y == z));
        logger.log(Level.INFO,
                "3. La valeur de x est comprise (non strictement) entre celle de y et celle de z et z est strictement"
                        + " plus grand que y : (z > y && x >= y && x <= z) = "
                        + (z > y && x >= y && x <= z));
        logger.log(Level.INFO,
                "4. Parmi les valeurs de x, y et z, deux au moins sont identiques : (x == y || y == z || z == x) = "
                        + (x == y || y == z || z == x));
        logger.log(Level.INFO,
                "5. Parmi les valeurs de x, y et z, deux au plus sont identiques : (x == y && y != z || y == z && z != x || z == x && x != y) = "
                        + (x == y && y != z || y == z && z != x || z == x && x != y));

        var joiner = new StringJoiner(", ");
        for (var i = 0; i <= 6; ++i) {
            var j = JourSemaine.fromIndex(i);

            if (Pattern.compile("lundi.*", Pattern.CASE_INSENSITIVE).matcher(j.toString()).find()) {
                joiner.add(j.toString());
            }

        }
        logger.log(Level.INFO, joiner);

        var now = LocalDate.now();
        logger.log(Level.INFO,
                "Aujourd'hui : " + JourSemaine.fromDate(now.getDayOfMonth(), now.getMonthValue(), now.getYear()));
        logger.log(Level.INFO, "An 2000 : " + JourSemaine.fromDate(1, 1, 2000));
        logger.log(Level.INFO, "Mon annif : " + JourSemaine.fromDate(6, 7, 2002));

        
    }

    public static double machinFormula(int nbIter) {
        double ret = 0;
        for (var i = 0; i <= nbIter; ++i) {
            var a = (i % 2 == 0) ? 1.0 : -1.0;
            var b = a / (2 * i + 1);
            var c = invPow(5, i);
            var d = invPow(239, i);
            ret += b * (c - d);
        }

        return ret;
    }

    public static double invPow(int a, int p) {
        return (p == 0) ? 1.0 : invPow(a, p - 1) / Math.pow(a, 2);
    }

}
