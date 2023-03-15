package com.example.tp.poste;

public class Magazine extends Courrier {

    public Magazine(String destination, double poids, ModeExpedition modeExpedition) {
        super(destination, poids, modeExpedition);
    }

    public Magazine(String destination, double poids) {
        super(destination, poids);
    }

    @Override
    public double calculerAfranchissement() {
        return determinerValidite() ? (5.0 * getPoids() / 1000) * getModeExpedition().getFacteur() : 0.0;
    }

}