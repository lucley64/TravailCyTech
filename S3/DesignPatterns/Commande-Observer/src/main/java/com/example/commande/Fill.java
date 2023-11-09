package com.example.commande;

public class Fill extends WaterMovement{

    public Fill(Can source){
        super(source);
    }

    @Override
    public void action() {
        transferredQuantity = source.getMaxVolume() - source.getVolume();
        source.fill();
    }

    @Override
    public void undo() {
        source.setVolume(source.getVolume() - transferredQuantity);
    }
}
