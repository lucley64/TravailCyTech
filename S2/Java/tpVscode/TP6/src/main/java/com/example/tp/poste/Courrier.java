package com.example.tp.poste;

public abstract class Courrier {
    private String destination;
    private double poids;
    private ModeExpedition modeExpedition;

    protected Courrier(String destination, double poids, ModeExpedition modeExpedition) {
        setDestination(destination);
        setPoids(poids);
        setModeExpedition(modeExpedition);
    }

    protected Courrier(String destination, double poids) {
        setDestination(destination);
        setPoids(poids);
        setModeExpedition(ModeExpedition.NORMAL);
    }

    public boolean determinerValidite() {
        return destination != null;
    }

    public abstract double calculerAfranchissement();

    protected enum ModeExpedition {
        NORMAL(1),
        EXPRESS(2);

        private int facteur;

        private ModeExpedition(int facteur) {
            this.facteur = facteur;
        }

        public int getFacteur() {
            return facteur;
        }

    }

    public String getDestination() {
        return destination;
    }

    public void setDestination(String destination) {
        this.destination = destination;
    }

    public double getPoids() {
        return poids;
    }

    public void setPoids(double poids) {
        this.poids = poids;
    }

    public ModeExpedition getModeExpedition() {
        return modeExpedition;
    }

    public void setModeExpedition(ModeExpedition modeExpedition) {
        this.modeExpedition = modeExpedition;
    }

    @Override
    public String toString() {
        var valide = determinerValidite();
        return getClass().getName() + (valide ? "" : " [invalide] ") + "\n" +
                "Destination: " + getDestination() + "\n" +
                "Poids: " + getPoids() + "grammes \n" +
                "Expression: " + (getModeExpedition() == ModeExpedition.EXPRESS ? "oui" : "non") + "\n" +
                "Prix: " + calculerAfranchissement() + " euros";
    }
}