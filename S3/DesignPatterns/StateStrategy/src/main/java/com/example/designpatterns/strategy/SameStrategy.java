package com.example.designpatterns.strategy;

public class SameStrategy implements Strategy{
    Attack attack;

    public SameStrategy(Attack attack){
        this.attack = attack;
    }

    @Override
    public Attack play() {
        return attack;
    }
}
