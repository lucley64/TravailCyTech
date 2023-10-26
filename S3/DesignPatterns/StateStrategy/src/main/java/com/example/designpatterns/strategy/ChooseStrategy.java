package com.example.designpatterns.strategy;


import java.util.Scanner;

public class ChooseStrategy implements Strategy{

    private final System.Logger log;
    private final Scanner scanner;

    public ChooseStrategy(System.Logger log, Scanner scanner){
        this.log = log;
        this.scanner = scanner;
    }

    @Override
    public Attack play() {
        int attack = -1;
        while (attack < 1 || attack > 3){
            log.log(System.Logger.Level.INFO, "Choose attack: [1: Rock, 2: Paper, 3: Scissors");
            attack = scanner.nextInt();
        }

        return Attack.values()[attack];
    }
}
