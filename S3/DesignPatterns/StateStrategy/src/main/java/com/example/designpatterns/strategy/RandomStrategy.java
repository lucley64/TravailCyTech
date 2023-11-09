package com.example.designpatterns.strategy;

import java.util.Random;

public class RandomStrategy implements Strategy {
    @Override
    public Attack play() {

        Random random = new Random(System.currentTimeMillis());
        int attack = random.nextInt(3) - 1;


        return Attack.values()[attack];
    }
}
