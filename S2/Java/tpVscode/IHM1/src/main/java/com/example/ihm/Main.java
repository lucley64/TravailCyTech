package com.example.ihm;

import java.io.File;

import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.layout.StackPane;
import javafx.stage.Stage;

public class Main extends Application {
    @Override
    public void start(Stage stage) throws Exception {
        stage.setTitle("Juste un bouton");
        Button b = new Button("clique moi");
        b.setPrefSize(400, 400);
        b.setId("cliqueMoi");
        StackPane root = new StackPane();
        root.getChildren().add(b);
        Scene scene = new Scene(root, 400, 400);
        File f = new File("src/main/res/css/style.css");
        scene.getStylesheets().add("file:///" + f.getAbsolutePath().replace("\\", "/"));
        stage.setScene(scene);
        stage.show();
    }

    public static void main(String[] args) {
        launch(args);
    }
}
