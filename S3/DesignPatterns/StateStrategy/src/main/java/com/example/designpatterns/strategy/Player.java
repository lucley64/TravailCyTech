package com.example.designpatterns.strategy;

public class Player {
    private final String name;
    private int score;

    private final Strategy strategy;

    public Player(String name, Strategy strategy){
        this.name = name;
        this.strategy = strategy;
        score = 0;
    }

    public Attack play(){
        return strategy.play();
    }

    public int addPoint(){
        return ++score;
    }

    public String getName() {
        return name;
    }

    @Override
    public String toString() {
        return "Player{" +
                "name='" + name + '\'' +
                ", score=" + score +
                '}';
    }
}
