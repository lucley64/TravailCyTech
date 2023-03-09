package com.example.tp.poste;

import com.example.tp.poste.Courrier.ModeExpedition;
import com.example.tp.poste.Lettre.Format;

public class BoiteAuxLettres {
    Courrier[] courriers;
    int indice;

    public BoiteAuxLettres(int contenance) {
        this.courriers = new Courrier[contenance];
        indice = 0;
    }

    public BoiteAuxLettres(Courrier[] courriers) {
        this.courriers = courriers;
        indice = courriers.length;
    }

    public int getNbCourriers() {
        return courriers.length;
    }

    public double coutAffranchissement() {
        var acc = 0.0;
        for (var courrier : courriers) {
            acc += courrier.calculerAfranchissement();
        }
        return acc;
    }

    public int nbInvalides() {
        var acc = 0;
        for (var courrier : courriers) {
            acc += (courrier.determinerValidite() ? 0 : 1);
        }
        return acc;
    }

    public void addCourier(Courrier courrier) {
        if (indice < courriers.length) {
            courriers[indice++] = courrier;
        } else {
            throw new StackOverflowError();
        }
    }

    public Courrier popCourier() {
        if (indice > 0) {
            return courriers[--indice];
        } else {
            throw new StackOverflowError();
        }
    }

    public Courrier[] getCouriers() {
        return courriers;
    }

    public static void main(String[] args) {
        var boite = new BoiteAuxLettres(50);
        boite.addCourier(new Lettre("Bordeaux", 100.0, ModeExpedition.EXPRESS, Format.A3));
    }
}