package com.example.designpatterns.state;

public interface KeypadState {


    boolean keyPressed(Keypad keypad, char c);
}
