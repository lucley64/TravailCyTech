package com.example.designpatterns.compositedecorator;

public class Menu extends Product{

    private Agrementable drink;
    private Snack snack;


    protected Menu(double price, String name, Agrementable drink, Snack snack) {
        super(price, name);
        this.snack = snack;
        this.drink = drink;
    }

    public Agrementable getDrink() {
        return drink;
    }

    public void setDrink(Agrementable drink) {
        this.drink = drink;
    }

    public Snack getSnack() {
        return snack;
    }

    public void setSnack(Snack snack) {
        this.snack = snack;
    }

    @Override
    public String toString() {
        return "menu (" + drink.getName() + " + " + snack.getName() + "): " + getPrice();
    }

    public static final Menu CHOCO_MUFFIN = new Menu(5.22, "Choco muffin", Drink.CHOCOLATE, Snack.MUFFIN);
}
