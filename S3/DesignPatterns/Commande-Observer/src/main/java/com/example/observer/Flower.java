package com.example.observer;

public class Flower extends Observable implements Observer {
    private final Season bloomSeason;

    private final String name;
    private boolean isBloom;

    private Garden garden;

    public Flower(Season bloomSeason, String name){
        this.bloomSeason = bloomSeason;
        this.name = name;
        garden = null;
    }

    public void setGarden(Garden garden) {
        this.garden = garden;
    }

    @Override
    public void update() {
        setBloom(bloomSeason == garden.getSeason());
    }

    public void setBloom(boolean bloom) {
        this.isBloom = bloom;
        notifyObservers();
    }

    public boolean isBloom() {
        return isBloom;
    }

    public String getName() {
        return name;
    }

    @Override
    public String toString() {
        return "Flower{" +
                "name='" + name + '\'' +
                ", isBloom=" + isBloom +
                '}';
    }
}
