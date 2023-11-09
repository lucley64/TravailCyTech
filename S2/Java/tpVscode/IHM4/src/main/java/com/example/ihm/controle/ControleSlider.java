package com.example.ihm.controle;

import java.util.Observable;
import java.util.Observer;

import com.example.ihm.albumphoto.Album;

import javafx.beans.value.ChangeListener;
import javafx.beans.value.ObservableValue;
import javafx.scene.control.Slider;

public class ControleSlider implements Observer, ChangeListener<Number> {

    private Slider slider;
    private Album album;

    public ControleSlider(Slider slider, Album album) {
        this.slider = slider;
        this.album = album;
    }

    @Override
    public void changed(ObservableValue<? extends Number> observable, Number oldValue, Number newValue) {
        album.redimensionnerPhotoCourante(newValue.floatValue());
    }

    @Override
    public void update(Observable arg0, Object arg1) {
        if (arg0.getClass().equals(Album.class)) {
            var alb = (Album) arg0;
            slider.valueProperty().set(alb.getPhotoCourante().getZoom());
        }
    }

}
