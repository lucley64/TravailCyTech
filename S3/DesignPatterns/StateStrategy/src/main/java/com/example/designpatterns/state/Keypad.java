package com.example.designpatterns.state;

public class Keypad {

    private KeypadState state = new KeypadZero();

    public void setState(KeypadState state) {
        this.state = state;
    }

    public KeypadState getState() {
        return state;
    }

    public boolean pressKey(char c){
        return state.keyPressed(this, c);
    }

}
