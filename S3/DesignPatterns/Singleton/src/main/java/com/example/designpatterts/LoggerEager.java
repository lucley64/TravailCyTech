package com.example.designpatterts;

public class LoggerEager {
    private int nbLoggedMessages;

    private static LoggerEager instance = new LoggerEager();
    
    private LoggerEager() {
        nbLoggedMessages = 0;
    }

    public static LoggerEager getInstance() {
        return instance;
    }

    public void log(String message) {
        nbLoggedMessages++;
        System.out.println(message);
    }
}
