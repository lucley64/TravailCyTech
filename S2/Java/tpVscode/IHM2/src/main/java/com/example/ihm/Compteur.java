package com.example.ihm;

import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.layout.StackPane;
import javafx.stage.Stage;

public class Compteur extends Application{
    @Override
    public void start(Stage primaryStage) throws Exception {
        primaryStage.setTitle("Juste un bouton");
        var b = new Button("0");
        b.setOnAction(ev -> b.setText(Integer.parseInt(b.getText()) + 1 + ""));
        var root = new StackPane();
        root.getChildren().add(b);
        var scene = new Scene(root, 400, 400);
        primaryStage.setScene(scene);
        primaryStage.show();
    }
}
