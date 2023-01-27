package com.example.tp;

import java.lang.System.Logger;
import java.lang.System.Logger.Level;

public class App {
    private static Logger logger = System.getLogger("mainLogger");

    public static void main(String[] args) {
        logger.log(Level.INFO, "Hello, World!");
    }
}
