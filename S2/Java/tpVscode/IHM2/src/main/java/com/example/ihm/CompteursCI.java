package com.example.ihm;

import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.layout.HBox;
import javafx.stage.Stage;

public class CompteursCI extends Application{

    @Override
    public void start(Stage primaryStage) throws Exception {
        primaryStage.setTitle("Juste un bouton");
        var b1 = new Button("0");
        var b2 = new Button("0");
        var b3 = new Button("0");

        b1.setOnAction(new ClickEvent());
        b2.setOnAction(new ClickEvent());
        b3.setOnAction(new ClickEvent());

        var root = new HBox();
        root.getChildren().add(b1);
        root.getChildren().add(b2);
        root.getChildren().add(b3);
        var scene = new Scene(root);
        primaryStage.setScene(scene);
        primaryStage.show();

    }

    private class ClickEvent implements EventHandler<ActionEvent>{
        @Override
        public void handle(ActionEvent event) {
            if (event.getTarget().getClass() == Button.class){
                var b = (Button) event.getTarget();
                b.setText(Integer.parseInt(b.getText()) + 1 + "");
            }
            
        }
    }
    
}
