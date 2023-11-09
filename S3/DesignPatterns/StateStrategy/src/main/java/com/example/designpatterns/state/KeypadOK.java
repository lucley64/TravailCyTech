package com.example.designpatterns.state;

public class KeypadOK implements KeypadState{
    @Override
    public boolean keyPressed(Keypad keypad, char c) {
        return true;
    }
}
