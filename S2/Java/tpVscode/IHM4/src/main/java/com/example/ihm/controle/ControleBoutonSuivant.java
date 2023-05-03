package com.example.ihm.controle;

import java.util.Observable;
import java.util.Observer;

import com.example.ihm.albumphoto.Album;

import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.scene.control.Button;

public class ControleBoutonSuivant implements Observer, EventHandler<ActionEvent> {

    private Button buttonSuiv;
    private Album album;

    public ControleBoutonSuivant(Button buttonSuiv, Album album) {
        this.buttonSuiv = buttonSuiv;
        this.album = album;
    }

    @Override
    public void handle(ActionEvent event) {
        album.setIndexCourant(album.getIndexCourant() + 1);
        buttonSuiv.setDisable(album.getIndexCourant() >= album.getSize() - 1);
    }

    @Override
    public void update(Observable arg0, Object arg1) {
        buttonSuiv.setDisable(album.getIndexCourant() >= album.getSize() - 1);
    }

}
