package com.example.tp.math.polynome;

import java.lang.System.Logger.Level;
import java.util.Arrays;
import java.util.StringJoiner;

public class Polynome {
    private Monome[] coeffs;

    public Polynome(Monome[] coeffs) {
        this.coeffs = Arrays.copyOf(coeffs, coeffs.length);
    }

    public int getLength() {
        return coeffs.length;
    }

    public int getDegree() {
        return getLength() - 1;
    }

    public Monome get(int i) {
        if (i > getLength())
            throw new ArrayIndexOutOfBoundsException();
        return coeffs[i];
    }

    @Override
    public String toString() {
        var joiner = new StringJoiner(" + ");
        for (var monome : coeffs) {
            var str = monome.toString();
            if (!str.equals(""))
                joiner.add(monome.toString());
        }
        return joiner.toString();
    }

    @Override
    public boolean equals(Object obj) {
        if (this == obj)
            return true;
        if (obj == null)
            return false;
        if (getClass() != obj.getClass())
            return false;

        Polynome other = (Polynome) obj;
        for (int i = 0; i < coeffs.length; i++) {
            if (!coeffs[i].equals(other.get(i)))
                return false;
        }
        return true;
    }

    public double evaluate(double x) {
        var acc = 0.0;

        for (var monome : coeffs) {
            acc += monome.calc(x);
        }

        return acc;
    }

    public Polynome derivate() {
        var ret = new Monome[getDegree()];
        for (var i = 0; i < getDegree(); i++) {
            ret[i] = get(i).derivate();
        }
        return new Polynome(ret);
    }

    @Override
    public int hashCode() {
        return super.hashCode();
    }

    public static void main(String[] args) {
        var logger = System.getLogger("main");
        Monome[] tab = {
                new Monome(3, 12),
                new Monome(1, -2),
                new Monome(20)
        };

        Monome[] tab2 = {
                new Monome(1, -2),
                new Monome(3, 12),
                new Monome(20)
        };

        var pol = new Polynome(tab);
        var pol2 = new Polynome(tab2);

        logger.log(Level.INFO, pol);
        logger.log(Level.INFO, pol.equals(pol2));
        logger.log(Level.INFO, pol.evaluate(2));
        logger.log(Level.INFO, pol.derivate());

    }
}