package com.example.designpatterns.compositedecorator;

import java.util.ArrayList;
import java.util.List;
import java.util.StringJoiner;

public class Order extends Component {
    private final List<Component> components;

    public Order() {
        this(new ArrayList<>());
    }

    public Order(List<Component> components) {
        this.components = components;
    }

    public boolean add(Component component) {
        return components.add(component);
    }

    public void empty() {
        components.clear();
    }

    public boolean remove(Component component) {
        return components.remove(component);
    }

    @Override
    public double getPrice() {
        double res = 0;
        for (var comp :
                components) {
            res += comp.getPrice();
        }
        return Double.parseDouble(String.format("%.2f", res));
    }

    public List<Component> getComponents() {
        return components;
    }

    @Override
    public String toString() {
        StringJoiner sj = new StringJoiner("\n");

        for (var comp: components
             ) {
            sj.add("- " + comp);
        }

        sj.add("Total: " + getPrice());

        return sj.toString();
    }
}
