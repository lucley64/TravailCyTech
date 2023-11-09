package com.example.designpatterns.state;

public class KeypadTwo implements KeypadState{
    @Override
    public boolean keyPressed(Keypad keypad, char c) {
        if (c == 'b'){
            keypad.setState(new KeypadThee());
            return true;
        }
        else {
            keypad.setState(new KeypadNoOK());
            return false;
        }

    }
}
