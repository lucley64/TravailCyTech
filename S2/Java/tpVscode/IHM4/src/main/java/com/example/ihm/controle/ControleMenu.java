package com.example.ihm.controle;

import com.example.ihm.albumphoto.Album;

import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.scene.control.MenuItem;
import javafx.stage.FileChooser;
import javafx.stage.FileChooser.ExtensionFilter;

public class ControleMenu implements EventHandler<ActionEvent> {

    private Album album;

    public ControleMenu(Album album) {
        this.album = album;
    }

    @Override
    public void handle(ActionEvent event) {
        FileChooser fileChooser = new FileChooser();
        fileChooser.setTitle("Choisir une image");
        fileChooser.setSelectedExtensionFilter(new ExtensionFilter("Images", "*.jpg", "*.png", "*.jpeg", "*.gif", "*.csv"));
        var photo = fileChooser.showOpenDialog(((MenuItem) event.getTarget()).getParentPopup().getOwnerWindow());
        album.addPhoto(photo.toURI().toString());
    }
    
}
