package com.example.designpatterns.compositedecorator;

public abstract class Agrementable extends Product{
    protected Agrementable(double price, String name) {
        super(price, name);
    }

    protected abstract String toStringNoPrice();
}
