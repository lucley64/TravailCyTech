package com.example.designpatterns.state;

public class KeypadThee implements KeypadState{
    @Override
    public boolean keyPressed(Keypad keypad, char c) {
        if (c == 'a'){
            keypad.setState(new KeypadOK());
            return true;
        }
        else {
            keypad.setState(new KeypadNoOK());
            return false;
        }

    }
}
