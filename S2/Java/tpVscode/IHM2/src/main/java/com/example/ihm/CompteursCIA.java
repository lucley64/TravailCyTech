package com.example.ihm;

import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.layout.HBox;
import javafx.stage.Stage;

public class CompteursCIA extends Application {

    @Override
    public void start(Stage primaryStage) throws Exception {
        primaryStage.setTitle("Juste un bouton");
        var b1 = new Button("0");
        var b2 = new Button("0");
        var b3 = new Button("0");

        b1.setOnAction(event -> b1.setText(Integer.parseInt(b1.getText()) + 1 + ""));
        b2.setOnAction(event -> b2.setText(Integer.parseInt(b2.getText()) + 1 + ""));
        b3.setOnAction(event -> b3.setText(Integer.parseInt(b3.getText()) + 1 + ""));

        var root = new HBox();
        root.getChildren().add(b1);
        root.getChildren().add(b2);
        root.getChildren().add(b3);
        var scene = new Scene(root);
        primaryStage.setScene(scene);
        primaryStage.show();

    }

}
