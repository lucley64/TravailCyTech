package com.example.ihm;

import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.Slider;
import javafx.scene.layout.HBox;
import javafx.scene.media.Media;
import javafx.scene.media.MediaPlayer;
import javafx.stage.FileChooser;
import javafx.stage.Stage;
import javafx.util.Duration;

public class LecteurAudio extends Application{

    @Override
    public void start(Stage primaryStage) throws Exception {
        primaryStage.setTitle("Juste un lecteur audio");
        var play = new Button("Play");
        var rewind = new Button("<<");
        var volumeLabel = new Label("Volume");
        var volumeSlider = new Slider(0, 1, 0);
        var root = new HBox(12);
        root.getChildren().add(play);
        root.getChildren().add(rewind);
        root.getChildren().add(volumeLabel);
        root.getChildren().add(volumeSlider);

        var fc = new FileChooser();
        fc.setTitle("Choisir une musique");
        var f = fc.showOpenDialog(primaryStage);


        var media = new Media(f.toURI().toString());
        var mediaPlayer = new MediaPlayer(media);
        
        play.setOnAction(ev -> {
            if (play.getText().equals("Play")) {
                play.setText("Pause");
                mediaPlayer.play();
            }
            else{
                play.setText("Play");
                mediaPlayer.pause();
            }
        });

        rewind.setOnAction(ev -> mediaPlayer.seek(Duration.ZERO));

        volumeSlider.valueProperty().bindBidirectional(mediaPlayer.volumeProperty());
        
        var scene = new Scene(root);
        primaryStage.setScene(scene);
        primaryStage.show();
    }
    
}
