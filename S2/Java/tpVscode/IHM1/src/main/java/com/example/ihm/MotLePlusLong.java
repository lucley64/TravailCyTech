package com.example.ihm;

import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.control.Label;
import javafx.scene.control.ListView;
import javafx.scene.control.TextField;
import javafx.scene.control.Tooltip;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.StackPane;
import javafx.stage.Stage;

public class MotLePlusLong extends Application {
    public static void main(String[] args) {
        launch(args);
    }

    @Override
    public void start(Stage primaryStage) throws Exception {
        primaryStage.setTitle("Mot Le Plus Long");
        var root = new StackPane();

        var vb = new BorderPane();
        var tf = new TextField("tes");
        var lf = new ListView<String>();
        var lb = new Label("Tirage : ");

        lf.getItems().addAll("est", "set", "tes");
        tf.setTooltip(new Tooltip("Veuillez indiquer les lettres du tirage."));

        vb.setTop(tf);
        vb.setCenter(lf);
        vb.setLeft(lb);
        root.getChildren().add(vb);
        var scene = new Scene(root, 400, 400);
        primaryStage.setScene(scene);
        primaryStage.show();

    }

}
