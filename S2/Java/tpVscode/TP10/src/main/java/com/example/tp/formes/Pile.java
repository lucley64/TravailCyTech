package com.example.tp.formes;

public interface Pile<T>{
    public void empiler(T f);
    public void depiler();
    public T sommet();
    public boolean vide();
    public void trier();
    public int taille();
    
}