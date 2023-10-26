package com.example.designpatterns.state;

public interface KeypadState {


    public abstract boolean keyPressed(Keypad keypad, char c);
}
