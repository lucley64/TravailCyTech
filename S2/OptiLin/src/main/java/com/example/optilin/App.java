package com.example.optilin;

import java.lang.System.Logger;
import java.lang.System.Logger.Level;
import java.util.ArrayList;
import java.util.List;

import com.example.optilin.Probleme.ProblemeNonBorneException;
import com.example.optilin.Probleme.ProblemeResoluException;

public class App {
    private static Logger logger = System.getLogger("main");

    public static void main(String[] args) {

        var p = new Probleme(                   new ArrayList<>(List.of(2.,  1.)));
        p.addContrainte(new Probleme.Contrainte(new ArrayList<>(List.of(1., -1.)), 1));
        p.addContrainte(new Probleme.Contrainte(new ArrayList<>(List.of(1.,  1.)), 1));

        logger.log(Level.INFO, p.toString());

        var t = new Probleme.Tableau(p);
        var i = 0;
        try {
            for (; i < 100; i++) {
                t.iteration();
            }
        } catch (ProblemeResoluException e) {
            logger.log(Level.INFO, e.toString());
            logger.log(Level.INFO, t.toString());
        } catch (ProblemeNonBorneException e) {
            logger.log(Level.ERROR, e.toString());

        }
    }
}