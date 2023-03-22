package com.example.tp.formes;

public interface PileFormes{
    public void empiler(IForme f);
    public void depiler();
    public IForme sommet();
    public boolean vide();
    public void trier();
}