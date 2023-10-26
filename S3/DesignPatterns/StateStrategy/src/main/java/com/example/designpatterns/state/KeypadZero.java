package com.example.designpatterns.state;

public class KeypadZero implements KeypadState{

    @Override
    public boolean keyPressed(Keypad keypad, char c) {
        if (c == 'a'){
            keypad.setState(new KeypadOne());
            return true;
        }
        else {
            keypad.setState(new KeypadNoOK());
            return false;
        }

    }
}
