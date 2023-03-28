package com.example.optilin;
public class App{
    public static void main(String[] args) {
        double[] x = {1, 0.5};
        double[] y = {1, 1};
        double[] v = {-3, 1};
        double[] z = {1, -0.5};

        Probleme p = new Probleme(x);

        p.addContrainte(new Probleme.Contrainte(y, 4));
        p.addContrainte(new Probleme.Contrainte(v, 3));
        p.addContrainte(new Probleme.Contrainte(z, 1));

        System.out.println(p.toString());
    }
}   