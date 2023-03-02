package com.example.tp;

public interface PileFormes{
    public void empiler(Forme f);
    public void depiler();
    public Forme sommet();
    public boolean vide();
}