package com.example.tp.poste;

public class Colis extends Courrier {
    private double volume;

    public Colis(String destination, double poids, ModeExpedition modeExpedition, double volume) {
        super(destination, poids, modeExpedition);
        this.volume = volume;
    }

    public Colis(String destination, double poids, double volume) {
        super(destination, poids);
        this.volume = volume;
    }

    public double getVolume() {
        return volume;
    }

    public void setVolume(double volume) {
        this.volume = volume;
    }

    @Override
    public double calculerAfranchissement() {
        return determinerValidite() ? (0.25 * getVolume() + getPoids() / 1000.0) * getModeExpedition().getFacteur()
                : 0.0;
    }

    @Override
    public boolean determinerValidite() {
        return super.determinerValidite() && getVolume() > 50;
    }

    @Override
    public String toString() {
        return super.toString() + "\n" + 
        "Volume: " + getVolume() + " litres";
    }
}