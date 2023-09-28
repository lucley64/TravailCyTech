package com.example;

public class Empty extends WaterMovement{
    protected Empty(Can source) {
        super(source);
    }

    @Override
    public void action() {
        transferredQuantity = source.getVolume();
        source.empty();
    }

    @Override
    public void undo() {
        source.setVolume(transferredQuantity);
    }
}
