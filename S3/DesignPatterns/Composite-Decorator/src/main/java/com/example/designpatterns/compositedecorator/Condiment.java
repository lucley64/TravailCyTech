package com.example.designpatterns.compositedecorator;

import org.jetbrains.annotations.Contract;
import org.jetbrains.annotations.NotNull;

import java.util.StringJoiner;

public class Condiment extends Agrementable{
    protected Condiment(double price, String name, Agrementable agrementable) throws Exception {
        super(price, name);
        this.agrementable = agrementable;
        if (limit(name) > 2) throw new Exception("limit reached");
    }

    @Override
    public double getPrice() {
        return Double.parseDouble(String.format("%.2f", super.getPrice() + agrementable.getPrice()));
    }

    private final Agrementable agrementable;

    public int limit(String name){
        int count;
        count = switch (agrementable){
            case Condiment c -> c.limit(name);
            default -> 0;
        };
        count += getName().equals(name) ? 1 : 0;
        return count;
    }

    @Contract("_ -> new")
    public static @NotNull Condiment milk(Agrementable agrementable) throws Exception {
        return new Condiment(.2, "Milk", agrementable);
    }

    @Contract("_ -> new")
    public static @NotNull Condiment moka(Agrementable agrementable) throws Exception {
        return new Condiment(.3, "Moka", agrementable);
    }

    @Contract("_ -> new")
    public static @NotNull Condiment soy(Agrementable agrementable) throws Exception {
        return new Condiment(.4, "Soy", agrementable);
    }

    public static Condiment cream(Agrementable agrementable) throws Exception {
        return new Condiment(.5, "Cream", agrementable);
    }
@Override
    public String toStringNoPrice(){
        StringJoiner sj = new StringJoiner(", ");

        sj.add(agrementable.toStringNoPrice());
        sj.add(getName());

        return sj.toString();
    }

    @Override
    public String toString() {


        return toStringNoPrice() + ": " + getPrice();
    }
}
