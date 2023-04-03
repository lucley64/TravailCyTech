package com.example.tp.paires;

import java.util.Comparator;

public class Paire<X, Y> implements Cloneable {
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

    public static class PaireComp<X1 extends Comparable<X1>, Y1 extends Comparable<Y1>> implements Comparator<Paire<X1, Y1>>{

        @Override
        public int compare(Paire<X1, Y1> arg0, Paire<X1, Y1> arg1) {
            if (arg0.equals(arg1))
                return 0;
            return ((arg0.getFirst().compareTo(arg1.getFirst()) > 1) || (arg0.getFirst().equals(arg1.getFirst()) && arg0.getSecond().compareTo(arg1.getSecond()) > 1))? 1 : -1;
        }

    }

    public static <X1 extends Number, X2 extends Number> double sumOfPaire(Paire<X1, X2> p){
        return p.getFirst().doubleValue() + p.getSecond().doubleValue();
    }

}
