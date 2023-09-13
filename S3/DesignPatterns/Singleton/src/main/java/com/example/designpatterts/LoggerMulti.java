package com.example.designpatterts;

import java.util.Optional;

public class LoggerMulti {
    private int nbLoggedMessages;
    private String logMessage;
    private static Optional<LoggerMulti> instanceLog = Optional.empty();
    private static Optional<LoggerMulti> instanceWarn = Optional.empty();
    private static Optional<LoggerMulti> instanceErr = Optional.empty();

    private LoggerMulti(String logMessage) {
        nbLoggedMessages = 0;
        this.logMessage = logMessage;
    }

    public static LoggerMulti getInstanceLog() {
        if (!instanceLog.isPresent()){
            instanceLog = Optional.of(new LoggerMulti("LOG"));
        }
        return instanceLog.get();
    }

    public static LoggerMulti getInstanceWarn() {
        if (!instanceWarn.isPresent()){
            instanceWarn = Optional.of(new LoggerMulti("WARNING"));
        }
        return instanceWarn.get();
    }

    public static LoggerMulti getInstanceErr() {
        if (!instanceErr.isPresent()){
            instanceErr = Optional.of(new LoggerMulti("ERROR"));
        }
        return instanceErr.get();
    }


    public void log(String message) {
        nbLoggedMessages++;
        System.out.println(logMessage + message);
    }
}
