package com.example.ihm.controle;

import java.util.Observable;
import java.util.Observer;

import com.example.ihm.albumphoto.Album;

import javafx.scene.image.ImageView;

public class ControlePhotoCentre implements Observer {

    private ImageView imageView;

    public ControlePhotoCentre(ImageView imageView) {
        this.imageView = imageView;
    }

    @Override
    public void update(Observable arg0, Object arg1) {
        if (arg0.getClass().equals(Album.class)) {
            var alb = (Album) arg0;
            imageView.setImage(alb.getPhotoCourante().getImage());
        }
    }

}
