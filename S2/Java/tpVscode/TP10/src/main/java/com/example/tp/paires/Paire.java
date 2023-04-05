package com.example.tp.paires;

import java.lang.System.Logger;
import java.lang.System.Logger.Level;
import java.util.Comparator;

public class Paire<X extends Comparable<X>, Y extends Comparable<Y>> implements Cloneable, Comparable<Paire<X, Y>> {
    private X first;
    private Y second;

    public Paire(X first, Y second) {
        setFirst(first);
        setSecond(second);
    }

    public X getFirst() {
        return first;
    }

    public void setFirst(X first) {
        this.first = first;
    }

    public Y getSecond() {
        return second;
    }

    public void setSecond(Y second) {
        this.second = second;
    }

    @Override
    public int hashCode() {
        final int prime = 31;
        int result = 1;
        result = prime * result + ((getFirst() == null) ? 0 : getFirst().hashCode());
        result = prime * result + ((getSecond() == null) ? 0 : getSecond().hashCode());
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
        Paire<?, ?> other = (Paire<?, ?>) obj;
        if (getFirst() == null) {
            if (other.getFirst() != null)
                return false;
        } else if (!getFirst().equals(other.getFirst()))
            return false;
        if (getSecond() == null) {
            if (other.getSecond() != null)
                return false;
        } else if (!getSecond().equals(other.getSecond()))
            return false;
        return true;
    }

    @Override
    public String toString() {
        return "Paire [first=" + getFirst() + ", second=" + getSecond() + "]";
    }

    @Override
    public Object clone() throws CloneNotSupportedException {
        return super.clone();
    }

    public static <T extends Comparable<T>> T plusGrand(Paire<T, T> p) {
        return (p.getFirst().compareTo(p.getSecond()) > 0 ? p.getFirst() : p.getSecond());
    }

    public static <X1 extends Number & Comparable<X1>, X2 extends Number & Comparable<X2>> double sumOfPaire(
            Paire<X1, X2> p) {
        return p.getFirst().doubleValue() + p.getSecond().doubleValue();
    }

    @Override
    public int compareTo(Paire<X, Y> o) {
        if (equals(o)) {
            return 0;
        }
        if (getFirst().compareTo(o.getFirst()) > 0
                || (getFirst().equals(o.getFirst()) && getSecond().compareTo(o.getSecond()) > 0)) {
            return 1;
        } else {
            return -1;
        }
    }

    public static class CompPaire1<X1 extends Comparable<X1>, Y1 extends Comparable<Y1>>
            implements Comparator<Paire<X1, Y1>> {
        @Override
        public int compare(Paire<X1, Y1> arg0, Paire<X1, Y1> arg1) {
            return arg0.getFirst().compareTo(arg1.getFirst());
        }
    }

    public static class CompPaire2<X1 extends Comparable<X1>, Y1 extends Comparable<Y1>>
            implements Comparator<Paire<X1, Y1>> {
        @Override
        public int compare(Paire<X1, Y1> arg0, Paire<X1, Y1> arg1) {
            return arg0.getSecond().compareTo(arg1.getSecond());
        }
    }

    public static class CompPaireSum<X1 extends Number & Comparable<X1>, Y1 extends Number & Comparable<Y1>>
            implements Comparator<Paire<X1, Y1>> {
        @Override
        public int compare(Paire<X1, Y1> arg0, Paire<X1, Y1> arg1) {
            double sum1 = sumOfPaire(arg0);
            double sum2 = sumOfPaire(arg1);
            if (sum1 < sum2) {
                return -1;
            } else if (sum1 > sum2) {
                return 1;
            } else {
                return 0;
            }
        }
    }

    public static void main(String[] args) {
        Paire<Integer, Double> p1 = new Paire<>(12, 0.5);
        Paire<Integer, Double> p2 = new Paire<>(24, 75.2);
        Paire<Integer, Double> p3 = new Paire<>(24, 99.0);

        Logger logger = System.getLogger("null");
        logger.log(Level.INFO, "p1.compareTo(p2) = " + p1.compareTo(p2));
        logger.log(Level.INFO, "p3.compareTo(p2) = " + p3.compareTo(p2));
        logger.log(Level.INFO, "p2.compareTo(p2) = " + p2.compareTo(p2));
        logger.log(Level.INFO, "new CompPaire1().compare(p2, p3) = " + new CompPaire1<Integer, Double>().compare(p2, p3));
        logger.log(Level.INFO, "new CompPaire2().compare(p2, p3) = " + new CompPaire2<Integer, Double>().compare(p2, p3));
        logger.log(Level.INFO, "new CompPaireSum().compare(p2, p3) = " + new CompPaireSum<Integer, Double>().compare(p2, p3));
    }
}
