package com.example;

public class Transfer extends WaterMovement {
    private final Can target;

    public Transfer(Can source, Can target){
        super(source);
        this.target = target;
    }

    @Override
    public void action() {
        transferredQuantity = source.decant(target);
    }

    @Override
    public void undo() {
        target.setVolume(target.getVolume() - transferredQuantity);
        source.setVolume(source.getVolume() + transferredQuantity);
    }
}
