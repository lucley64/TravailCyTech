package com.example.tp.poste;

public class Lettre extends Courrier {

    private Format format;

    public Lettre(String destination, double poids, ModeExpedition modeExpedition, Format format) {
        super(destination, poids, modeExpedition);
        this.format = format;
    }

    public Lettre(String destination, double poids, Format format) {
        super(destination, poids);
        this.format = format;
    }

    @Override
    public double calculerAfranchissement() {
        return determinerValidite() ? (format.getPrix() + getPoids() / 1000.0) * getModeExpedition().getFacteur() : 0.0;
    }

    public enum Format {
        A3(3.5),
        A4(2.5),
        A5(3.5);

        private double prix;

        private Format(double prix) {
            this.prix = prix;
        }

        public double getPrix() {
            return this.prix;
        }
    }

    public Format getFormat() {
        return format;
    }

    public void setFormat(Format format) {
        this.format = format;
    }

    @Override
    public String toString() {
        return super.toString() + "\n" +
                "Format: " + getFormat();
    }
}