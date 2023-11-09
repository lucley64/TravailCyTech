package com.example.observer;

import java.util.List;

public class MainObserver {
    static System.Logger logger = System.getLogger("main");
    public static void main(String[] args) {
        Flower iris = new Flower(Season.SPRING, "Iris");
        Flower daylily = new Flower(Season.SUMMER, "Daylily");
        Flower margerite = new Flower(Season.AUTUMN, "Margerite");
        Flower snowdrop = new Flower(Season.WINTER, "Snowdrop");

        Garden garden = new Garden(Season.SPRING, List.of(iris, margerite, daylily, snowdrop));

        Bee bee = new Bee(snowdrop);

        logger.log(System.Logger.Level.INFO, bee);

        garden.changeSeason();

        logger.log(System.Logger.Level.INFO, bee);

        garden.changeSeason();

        logger.log(System.Logger.Level.INFO, bee);

        garden.changeSeason();

        logger.log(System.Logger.Level.INFO, bee);


    }
}
