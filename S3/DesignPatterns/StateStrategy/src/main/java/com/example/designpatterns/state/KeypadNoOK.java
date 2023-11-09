package com.example.designpatterns.state;

public class KeypadNoOK implements KeypadState{
    @Override
    public boolean keyPressed(Keypad keypad, char c) {
        keypad.setState(new KeypadZero());
        return true;
    }
}
