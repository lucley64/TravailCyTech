package com.example.tp.formes;

import java.util.StringJoiner;

@SuppressWarnings("unchecked")
public abstract class PileA<T> implements Pile<T>, Cloneable {

    @Override
    public String toString() {
        var s = new StringJoiner(", ");
        try {
            var me = (PileA<T>) clone();
            for (var i = 0; i < taille(); i++) {
                s.add(me.sommet().toString());
                me.depiler();
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
        return "[ " + s + " ]";
    }

    @Override
    public boolean equals(Object obj) {
        if (this == obj)
            return true;
        if (obj == null)
            return false;
        if (getClass() != obj.getClass())
            return false;
        try {
            var other = (PileA<T>) ((PileA<T>) obj).clone();
            var me = (PileA<T>) clone();

            while (!me.vide()) {
                var f1 = me.sommet();
                var f2 = other.sommet();

                if (!f1.equals(f2))
                    return false;
                me.depiler();
                other.depiler();
            }

            return taille() == ((PileA<T>) obj).taille();
        } catch (Exception e) {
            return false;
        }
    }

    @Override
    public int hashCode() {
        return super.hashCode();
    }
}
