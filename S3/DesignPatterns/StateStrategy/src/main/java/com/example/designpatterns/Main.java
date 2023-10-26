package com.example.designpatterns;

import com.example.designpatterns.state.Keypad;
import com.example.designpatterns.state.KeypadOK;
import com.example.designpatterns.strategy.*;

import java.util.Scanner;

public class Main {
    static final System.Logger log = System.getLogger("main");

    public static void main(String[] args) {
        strategy();
    }


    public static void state() {
        Keypad keypad = new Keypad();
        Scanner scanner = new Scanner(System.in);

        while (!(keypad.getState() instanceof KeypadOK)) {
            log.log(System.Logger.Level.INFO, "Press key");
            String out = scanner.next();
            char ch = out.charAt(0);

            if (!keypad.pressKey(ch)) {
                log.log(System.Logger.Level.INFO, "Retry");
                keypad.pressKey(' ');
            } else {
                log.log(System.Logger.Level.INFO, "Good");
                if (!(keypad.getState() instanceof KeypadOK)) {
                    log.log(System.Logger.Level.INFO, "Continue...");
                }
            }
        }
        log.log(System.Logger.Level.INFO, "Keypad unlocked");
    }

    static void strategy() {
        Player player1 = new Player("player1", new RandomStrategy());
        Player player2 = new Player("player2", new SameStrategy(Attack.PAPER));
        Player player3 = new Player("player3", new ChooseStrategy(log, new Scanner(System.in)));

        log.log(System.Logger.Level.INFO, "player 1 vs player 2");
        int result = player1.play().compare(player2.play());
        printRes(result, player1, player2);

        log.log(System.Logger.Level.INFO, "player 2 vs player 3");
        result = player2.play().compare(player3.play());
        printRes(result, player2, player3);

        log.log(System.Logger.Level.INFO, "player 3 vs player 1");
        result = player3.play().compare(player1.play());
        printRes(result, player3, player1);


        log.log(System.Logger.Level.INFO, player1);
        log.log(System.Logger.Level.INFO, player2);
        log.log(System.Logger.Level.INFO, player3);

    }

    static void printRes(int res, Player one, Player two) {
        if (res < 0) {
            two.addPoint();
            log.log(System.Logger.Level.INFO, two + " won");
        } else if (res > 0) {
            one.addPoint();
            log.log(System.Logger.Level.INFO, one + " won");
        } else {
            log.log(System.Logger.Level.INFO, "no one won");
        }
    }
}