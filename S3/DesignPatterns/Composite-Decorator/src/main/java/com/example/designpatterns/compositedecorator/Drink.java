package com.example.designpatterns.compositedecorator;

public class Drink extends Agrementable{
    protected Drink(double price, String name) {
        super(price, name);
    }

    @Override
    protected String toStringNoPrice() {
        return getName();
    }

    public static final Drink EXPRESSO = new Drink(2.75, "Expresso");
    public static final Drink CHOCOLATE = new Drink(3.55, "Chocolate");
    public static final Drink COFFEE = new Drink(1.75, "Coffee");
    public static final Drink DECA = new Drink(2.5, "Deca");
    public static final Drink THE = new Drink(3.15, "The");
}
