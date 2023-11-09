package com.example.ihm.controle;

import java.util.Observable;
import java.util.Observer;

import com.example.ihm.albumphoto.Album;

import javafx.scene.control.Button;
import javafx.scene.image.ImageView;
import javafx.scene.layout.Pane;

public class ControleBandeauBas implements Observer {

    private Pane pane;

    public ControleBandeauBas(Pane pane) {
        this.pane = pane;
    }

    @Override
    public void update(Observable arg0, Object arg1) {
        if (arg1.equals(Album.NOUVELLE_IMAGE)) {
            var alb = (Album) arg0;
            var b = new Button("", new ImageView(alb.getPhoto(alb.getSize() - 1).getIcone()));
            var controleBoutonBas = new ControleBoutonBas(alb, b);
            b.setOnAction(controleBoutonBas);
            alb.addObserver(controleBoutonBas);
            pane.getChildren().add(b);
        }
    }

}
