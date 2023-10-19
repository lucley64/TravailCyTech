package com.example.designpatterns.adapter;

import org.jetbrains.annotations.Contract;

import java.util.Enumeration;
import java.util.Iterator;
import java.util.NoSuchElementException;

public class Adapter<T> implements Iterator<T> {

    Enumeration<T> enumeration;

    @Contract(pure = true)
    public Adapter(Enumeration<T> enumeration) {
        this.enumeration = enumeration;
    }


    @Override
    public boolean hasNext() {
        return enumeration.hasMoreElements();
    }

    @Override
    public T next() {
        if (!enumeration.hasMoreElements()) {
            throw new NoSuchElementException();
        }
        return enumeration.nextElement();
    }
}
