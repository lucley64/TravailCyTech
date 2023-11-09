package com.example.observer;

public class Bee implements Observer{
    private final Flower flower;
    private boolean isForaging;

    public Bee(Flower flower){
        flower.attach(this);
        this.flower = flower;
        isForaging = flower.isBloom();
    }

    public Flower getFlower() {
        return flower;
    }

    public boolean isForaging() {
        return isForaging;
    }

    @Override
    public void update() {
        isForaging = flower.isBloom();
    }

    @Override
    public String toString() {
        return "The bee is " + (isForaging ? "" : "not ") + "foraging the " + flower;
    }
}
