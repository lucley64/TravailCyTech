package com.example.designpatterns.state;

public class KeypadOne implements KeypadState {
    @Override
    public boolean keyPressed(Keypad keypad, char c) {
        if (c == 'b'){
            keypad.setState(new KeypadTwo());
            return true;
        }
        else {
            keypad.setState(new KeypadNoOK());
            return false;
        }

    }
}
