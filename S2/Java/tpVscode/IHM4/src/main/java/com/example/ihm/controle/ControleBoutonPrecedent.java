package com.example.ihm.controle;

import java.util.Observable;
import java.util.Observer;

import com.example.ihm.albumphoto.Album;

import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.scene.control.Button;

public class ControleBoutonPrecedent implements Observer, EventHandler<ActionEvent> {

    private Button buttonPrev;
    private Album album;

    public ControleBoutonPrecedent(Button buttonPrev, Album album) {
        this.buttonPrev = buttonPrev;
        this.album = album;
    }

    @Override
    public void handle(ActionEvent event) {
        album.setIndexCourant(album.getIndexCourant() - 1);
        buttonPrev.setDisable(album.getIndexCourant() <= 0);
    }

    @Override
    public void update(Observable arg0, Object arg1) {
        buttonPrev.setDisable(album.getIndexCourant() <= 0);
    }

}
