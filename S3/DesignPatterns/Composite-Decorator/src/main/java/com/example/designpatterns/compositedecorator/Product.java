package com.example.designpatterns.compositedecorator;

public abstract class Product extends Component {
    private double price;
    private String name;

    @Override
    public double getPrice(){
        return price;
    }

    protected Product(double price, String name){
        this.name = name;
        this.price = price;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setPrice(double price) {
        this.price = price;
    }

    public String getName() {
        return name;
    }

    @Override
    public String toString() {
        return name + ": " + price;
    }
}
