package com.example.optilin;

import java.util.ArrayList;
import java.util.List;
import java.util.StringJoiner;

public class Probleme {
    public static class Contrainte {
        private double[] coeficients;
        private double secondMembre;

        public Contrainte(double[] coeficients, double secondMembre) {
            this.coeficients = coeficients;
            this.secondMembre = secondMembre;
        }

        public double[] getCoeficients() {
            return coeficients;
        }

        public void setCoeficients(double[] coeficients) {
            this.coeficients = coeficients;
        }

        public double getSecondMembre() {
            return secondMembre;
        }

        public void setSecondMembre(double secondMembre) {
            this.secondMembre = secondMembre;
        }

        @Override
        public String toString() {
            StringJoiner ret = new StringJoiner(" + ");
            int i = 1;
            for (var coef : coeficients) {
                ret.add(coef + " × x" + i++);
            }
            return ret.toString() + " ≤ " + secondMembre;
        }

    }

    public static class Critaire {
        private double[] coeficients;

        public Critaire(double[] coeficients) {
            this.coeficients = coeficients;
        }

        public double[] getCoeficients() {
            return coeficients;
        }

        public void setCoeficients(double[] coeficients) {
            this.coeficients = coeficients;
        }

        @Override
        public String toString() {
            StringJoiner ret = new StringJoiner(" + ");
            int i = 1;

            for (var coef : coeficients) {
                ret.add(coef + " × x" + i++);
            }
            return "max\t" + ret.toString();
        }

    }

    private List<Contrainte> contraintes = new ArrayList<>();
    private Critaire critaire;

    public Probleme(double[] coefCritaire) {
        this.critaire = new Critaire(coefCritaire);
    }

    public List<Contrainte> getContraintes() {
        return contraintes;
    }

    public Critaire getCritaire() {
        return critaire;
    }

    public void setContraintes(List<Contrainte> contraintes) {
        this.contraintes = contraintes;
    }

    public void setCritaire(Critaire critaire) {
        this.critaire = critaire;
    }

    public void addContrainte(Contrainte contrainte) {
        this.contraintes.add(contrainte);
    }

    @Override
    public String toString() {
        StringJoiner ret = new StringJoiner("\n\t");
        ret.add(critaire.toString());
        contraintes.forEach(c -> ret.add(c.toString()));
        StringJoiner sj2 = new StringJoiner(", ");
        for (var i = 1; i < critaire.getCoeficients().length + 1; i++){
            sj2.add("x" + i);
        }
        ret.add(sj2.toString() + " ≥ 0");
        return ret.toString();
    }

}
