package com.example.tp.secret;

public class Vigenere implements Cryptage{
    private String cle;
    public void setCle(String cle) {
        this.cle = cle;
    }
    public Vigenere(String cle){
        setCle(cle.toUpperCase());
    }

    @Override
    public String encryprer(String message) {
        
        return message;
    }
}