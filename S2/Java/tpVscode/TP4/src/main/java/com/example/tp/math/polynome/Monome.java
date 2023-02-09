package com.example.tp.math.polynome;

public class Monome {
    private int exposant;
    private int coeficient;

    public Monome(int coeficient) {
        this.coeficient = coeficient;
        exposant = 0;
    }

    public Monome(int exposant, int coeficient) {
        this.exposant = exposant;
        this.coeficient = coeficient;
    }

    public int getExposant() {
        return exposant;
    }

    public void setExposant(int exposant) {
        this.exposant = exposant;
    }

    public int getCoeficient() {
        return coeficient;
    }

    public void setCoeficient(int coeficient) {
        this.coeficient = coeficient;
    }

    public double calc(double x) {
        return coeficient * Math.pow(x, exposant);
    }

    @Override
    public String toString() {
        var x = (exposant > 0) ? " * x" : "";
        var pow = (exposant > 1) ? x + "^" + exposant : x;
        var a = (coeficient > 0) ? coeficient : "( - " + -coeficient + " )";
        return (coeficient == 0) ? "" : a + pow;
    }

    @Override
    public int hashCode() {
        final int prime = 31;
        int result = 1;
        result = prime * result + exposant;
        result = prime * result + coeficient;
        return result;
    }

    @Override
    public boolean equals(Object obj) {
        if (this == obj)
            return true;
        if (obj == null)
            return false;
        if (getClass() != obj.getClass())
            return false;
        Monome other = (Monome) obj;
        return exposant != other.exposant || coeficient != other.coeficient;
    }

    public Monome derivate(){
        return new Monome(exposant - 1, coeficient * exposant);
    }

}