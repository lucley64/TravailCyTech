package com.example.tp.formes;

import java.util.Comparator;
import java.util.LinkedList;
import java.util.List;

public class PileList<T extends Comparable<T>> extends PileA<T>{
    List<T> items;

    public PileList() {
        items = new LinkedList<>();
    }

    @Override
    public void empiler(T f) {
        items.add(f);
    }

    @Override
    public void depiler() {
        items.remove(0);
    }

    @Override
    public T sommet() {
        return items.get(items.size()-1);
    }

    @Override
    public boolean vide() {
        return items.isEmpty();
    }

    @Override
    public void trier() {
        items.sort(Comparator.naturalOrder());
    }

    @Override
    public int taille() {
        return items.size();
    }

    @Override
    public int hashCode() {
        final int prime = 31;
        int result = super.hashCode();
        result = prime * result + ((items == null) ? 0 : items.hashCode());
        return result;
    }

    @SuppressWarnings("unchecked")
    @Override
    public boolean equals(Object obj) {
        if (this == obj)
            return true;
        if (!super.equals(obj))
            return false;
        if (getClass() != obj.getClass())
            return false;
        PileList<T> other = (PileList<T>) obj;
        if (items == null) {
            if (other.items != null)
                return false;
        } else if (!items.equals(other.items))
            return false;
        return true;
    }
    
}
