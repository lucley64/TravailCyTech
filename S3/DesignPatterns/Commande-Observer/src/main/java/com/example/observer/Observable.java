package com.example.observer;

import java.util.ArrayList;
import java.util.List;

public abstract class Observable {
    private final List<Observer> observers;

    protected Observable(){
        observers = new ArrayList<>();
    }

    public boolean attach(Observer obs){
        return observers.add(obs);
    }

    public boolean detach(Observer obs){
        return observers.remove(obs);

    }

    public void notifyObservers(){
        observers.forEach(Observer::update);
    }
}
