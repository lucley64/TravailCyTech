package com.example.designpatterts;

import java.util.Optional;

public class Logger {
    private int nbLoggedMessages;
    private static Optional<Logger> instance = Optional.empty();
    private Logger() {
        nbLoggedMessages = 0;
    }

    public static Logger getInstance() {
        if (!instance.isPresent()){
            instance = Optional.of(new Logger());
        }
        return instance.get();
    }

    public void log(String message) {
        nbLoggedMessages++;
        System.out.println(message);
    }
}
