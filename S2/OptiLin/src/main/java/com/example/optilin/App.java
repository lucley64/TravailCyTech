package com.example.optilin;

import java.util.List;

public class App {
    public static void main(String[] args) {

        var p = new Probleme(                   List.of( 1.0,  0.5).toArray(new Double[0]));
        p.addContrainte(new Probleme.Contrainte(List.of( 1.0,  1.0).toArray(new Double[0]), 4));
        p.addContrainte(new Probleme.Contrainte(List.of(-3.0,  1.0).toArray(new Double[0]), 3));
        p.addContrainte(new Probleme.Contrainte(List.of( 1.0, -0.5).toArray(new Double[0]), 1));
        
        System.out.println(p.toString());

        var t = new Probleme.Tableau(p);
        try {
            t.iteration();
        }
        catch(Exception e) {
            e.printStackTrace();
        }

        System.out.println(t.toString());

    }
}