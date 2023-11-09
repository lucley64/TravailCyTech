package com.example.commande;

public abstract class WaterMovement implements Command{
    protected Can source;
    protected int transferredQuantity;

    protected WaterMovement(Can source){
        this.source = source;
        transferredQuantity = 0;
    }
}
