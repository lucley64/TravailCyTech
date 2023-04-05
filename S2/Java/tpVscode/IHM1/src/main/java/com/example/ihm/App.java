package com.example.ihm;

import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.layout.StackPane;
import javafx.stage.Stage;

public class App extends Application {
    @Override
    public void start(Stage stage) throws Exception {
        stage.setTitle("myApplication");
        Button b = new Button("myButton");
        StackPane root = new StackPane();
        root.getChildren().add(b);
        Scene scene = new Scene(root, 500, 300);
        stage.setScene(scene);
        stage.show();
    }

    public static void main(String[] args) {
        launch(args);
    }
}
