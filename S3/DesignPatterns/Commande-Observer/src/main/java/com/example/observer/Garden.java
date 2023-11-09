package com.example.observer;

import java.util.ArrayList;
import java.util.List;

public class Garden extends Observable {
    private final List<Flower> flowers;
    private Season season;

    public Garden(){
        this(Season.SPRING);
    }

    public Garden(Season startSeason){
        this(startSeason, new ArrayList<>());
    }

    public Garden(Season startSeason, List<Flower> flowers){
        season = startSeason;
        this.flowers = new ArrayList<>();
        for (var flower :
                flowers) {
            addFlower(flower);
        }

    }

    public void addFlower(Flower flower){
        flower.setGarden(this);
        flowers.add(flower);
        attach(flower);
    }

    public Season changeSeason(){
        season = season.next();
        notifyObservers();
        return season;
    }

    public List<Flower> getFlowers() {
        return flowers;
    }

    public Season getSeason() {
        return season;
    }
}
