package com.example.optilin;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringJoiner;
import java.util.stream.IntStream;
import static java.util.Comparator.comparingDouble;

public class Probleme {
    public static class Contrainte {
        private Double[] coeficients;
        private double secondMembre;

        public Contrainte(Double[] coeficients, double secondMembre) {
            this.coeficients = coeficients;
            this.secondMembre = secondMembre;
        }

        public Double[] getCoeficients() {
            return coeficients;
        }

        public void setCoeficients(Double[] coeficients) {
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
        private Double[] coeficients;

        public Critaire(Double[] coeficients) {
            this.coeficients = coeficients;
        }

        public Double[] getCoeficients() {
            return coeficients;
        }

        public void setCoeficients(Double[] coeficients) {
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

    public Probleme(Double[] coefCritaire) {
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
        for (var i = 1; i < critaire.getCoeficients().length + 1; i++) {
            sj2.add("x" + i);
        }
        ret.add(sj2.toString() + " ≥ 0");
        return ret.toString();
    }

    public static class Tableau {
        private Ligne critair;
        private List<Ligne> contraintes;

        public Ligne getCritair() {
            return critair;
        }

        public List<Ligne> getContraintes() {
            return contraintes;
        }

        public Tableau(Probleme pb) {
            var l = new ArrayList<Double>();
            l.addAll(Arrays.asList(pb.critaire.coeficients));
            l.addAll(List.of(0.0, 0.0, 0.0));
            critair = new Ligne(l, 0.0, "f");
            contraintes = new ArrayList<>();
            int i = 1;
            for (var c : pb.contraintes) {
                l = new ArrayList<Double>();
                l.addAll(Arrays.asList(c.coeficients));
                for (var j = 0; j < pb.contraintes.size() - 1; j++) {
                    l.add(0.0);
                }
                l.add(pb.contraintes.size() - 1 + i - 1, 1.0);
                contraintes.add(new Ligne(l, c.secondMembre, "y" + i++));
            }
        }

        public void iteration() throws Exception {
            var max = critair.maxIndex();
            var min = Double.MAX_VALUE;
            String minName = null;
            if (max >= 0) {
                for (var c : contraintes) {
                    if (c.coefs.get(max) > 0 && min > c.secondMembre / c.coefs.get(max)) {
                        min = c.secondMembre / c.coefs.get(max);
                        minName = c.nom;
                    }
                }
            }

            if (max < 0 || minName == null) {
                throw new Exception("fin");
            }

            var plusPetit = getFromName(minName);
            plusPetit.multiplication(1 / plusPetit.coefs.get(max));
            plusPetit.setNom(getColName(max + 1));

            critair.add(plusPetit.mult(-1 * critair.coefs.get(max)));
            for (var c : contraintes) {
                if (!c.nom.equals(plusPetit.nom)) {
                    c.add(plusPetit.mult(-1 * c.coefs.get(max)));
                }
            }

        }

        public Ligne getFromName(String name) {
            for (var c : contraintes) {
                if (c.nom.equals(name))
                    return c;
            }
            return null;
        }

        public String getColName(int col) {
            if (col - 1 >= critair.coefs.size())
                throw new IndexOutOfBoundsException();
            if (col - 1 >= critair.coefs.size() - contraintes.size()) {
                return "y" + (col - critair.coefs.size());
            } else {
                return "x" + col;
            }
        }

        @Override
        public String toString() {
            var sj = new StringJoiner(", ");
            for (var c : contraintes) {
                sj.add(c.nom + ": " + c.secondMembre);
            }
            return "Optimum = (" + sj.toString() + "), Valeur = " + -critair.secondMembre;
        }

    }

    public static class Ligne {
        private List<Double> coefs;
        private double secondMembre;
        private String nom;

        public void setNom(String nom) {
            this.nom = nom;
        }

        public Ligne(List<Double> coefs, double secondMembre, String nom) {
            this.coefs = coefs;
            this.secondMembre = secondMembre;
            this.nom = nom;
        }

        public Ligne(Ligne that) {
            nom = that.nom;
            secondMembre = that.secondMembre;
            coefs = List.copyOf(that.coefs);
        }

        public List<Double> getCoefs() {
            return coefs;
        }

        public double getSecondMembre() {
            return secondMembre;
        }

        public String getNom() {
            return nom;
        }

        public void multiplication(double coef) {
            coefs.forEach(v -> v = v.doubleValue() * coef);
            secondMembre *= coef;
        }

        public Ligne mult(double coef) {
            var other = new Ligne(this);
            other.multiplication(coef);
            return other;
        }

        public void add(Ligne other) {
            if (coefs.size() == other.coefs.size()) {
                for (var i = 0; i < coefs.size(); i++) {
                    coefs.set(i, coefs.get(i).doubleValue() + other.coefs.get(i).doubleValue());
                }
                secondMembre += other.secondMembre;
            } else {
                throw new UnsupportedOperationException();
            }
        }

        public int maxIndex() {
            var v = IntStream.range(0, coefs.size()).boxed().max(comparingDouble(coefs::get));
            return v.isPresent() ? v.get() : -1;
        }

    }

}
