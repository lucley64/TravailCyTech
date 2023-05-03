package com.example.ihm.controle;

import java.util.Observable;
import java.util.Observer;

import com.example.ihm.albumphoto.Album;

import javafx.beans.value.ChangeListener;
import javafx.beans.value.ObservableValue;
import javafx.scene.control.ListView;

public class ControleListe implements Observer, ChangeListener<Number> {

    private Album album;
    private ListView<String> photos;

    public ControleListe(Album album, ListView<String> photos) {
        this.album = album;
        this.photos = photos;
    }

    @Override
    public void changed(ObservableValue<? extends Number> observable, Number oldValue, Number newValue) {
        album.setIndexCourant(newValue.intValue());
    }

    @Override
    public void update(Observable arg0, Object arg1) {
        var alb = (Album) arg0;
        photos.getSelectionModel().select(alb.getIndexCourant());

        if (arg1.equals(Album.NOUVELLE_IMAGE)) {
            photos.getItems().add(alb.getPhoto(alb.getSize()-1).getNom());
        }
    }

}
