package com.example.ihm.controle;

import java.util.Observable;
import java.util.Observer;

import com.example.ihm.albumphoto.Album;

import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.scene.control.Button;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;

public class ControleBoutonBas implements Observer, EventHandler<ActionEvent> {

    private Album album;
    private Button button;
    private final static String ACTIVE = "active";

    public ControleBoutonBas(Album album, Button button) {
        this.album = album;
        this.button = button;
    }

    @Override
    public void handle(ActionEvent event) {
        for (var i = 0; i < album.getSize(); i++) {
            if (album.getPhoto(i).getIcone().getUrl().equals(((ImageView) button.getGraphic()).getImage().getUrl())) {
                album.setIndexCourant(i);
                button.getStyleClass().add(ACTIVE);
            }
        }
    }

    @Override
    public void update(Observable arg0, Object arg1) {
        if (album.getPhotoCourante().getIcone().getUrl().equals(((ImageView) button.getGraphic()).getImage().getUrl())) {
            button.getStyleClass().add(ACTIVE);
        } else {
            button.getStyleClass().removeIf(elem -> elem.equals(ACTIVE));
        }
    }

}
