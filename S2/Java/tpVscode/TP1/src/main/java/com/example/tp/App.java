package com.example.tp;

import java.lang.System.Logger.Level;

public class App {
    public static void main(String[] args) {
		var logger = System.getLogger("mainLogger");
		logger.log(Level.INFO, "Hello, World!");
    }
}
