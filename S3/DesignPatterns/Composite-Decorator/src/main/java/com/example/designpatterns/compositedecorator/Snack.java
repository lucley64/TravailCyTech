package com.example.designpatterns.compositedecorator;

public class Snack extends Product{
    protected Snack(double price, String name) {
        super(price, name);
    }

    public static final Snack PASTRIES = new Snack(2.25, "Pastries");
    public static final Snack VIENNOISERIE = new Snack(1.5, "Vienoiserie");
    public static final Snack MUFFIN = new Snack(2.25, "Muffin");
    public static final Snack COOKIE = new Snack(1.95, "Cookie");
    public static final Snack DONUT = new Snack(2, "Donut");
    public static final Snack SANDWICH = new  Snack(5.45, "Sandwich");
}
