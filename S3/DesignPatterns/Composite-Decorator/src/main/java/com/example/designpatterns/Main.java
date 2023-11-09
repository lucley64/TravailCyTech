package com.example.designpatterns;

import static com.example.designpatterns.compositedecorator.Condiment.moka;
import static com.example.designpatterns.compositedecorator.Condiment.milk;
import static com.example.designpatterns.compositedecorator.Condiment.soy;
import static com.example.designpatterns.compositedecorator.Drink.COFFEE;
import static com.example.designpatterns.compositedecorator.Menu.CHOCO_MUFFIN;
import com.example.designpatterns.compositedecorator.Order;

public class Main {
    public static void main(String[] args) throws Exception {

        Order order = new Order();

        order.add(CHOCO_MUFFIN);
        order.add(moka(moka(COFFEE)));
        order.add(milk(soy(COFFEE)));

        System.out.println(order);
    }
}