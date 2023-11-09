package com.example.ihm;

import java.util.ArrayList;
import java.util.List;

import javafx.application.Application;
import javafx.geometry.Point2D;
import javafx.scene.Scene;
import javafx.scene.canvas.Canvas;
import javafx.scene.canvas.GraphicsContext;
import javafx.scene.control.Button;
import javafx.scene.layout.HBox;
import javafx.scene.layout.VBox;
import javafx.scene.paint.Color;
import javafx.stage.Stage;

public class PointsARelier extends Application {

    private List<Point2D> points = new ArrayList<>();
    private int prevI = 0;

    @Override
    public void start(Stage primaryStage) throws Exception {
        primaryStage.setTitle("Points à relier");
        var canvas = new Canvas(500, 500);
        var buttonOne = new Button("Relier pas à pas");
        var buttonFull = new Button("Relier tous");
        var buttons = new HBox(buttonOne, buttonFull);
        buttons.setStyle("-fx-alignment: center ;-fx-background-color: #dddddd;");
        buttons.setSpacing(12);
        var root = new VBox(canvas, buttons);
        var scene = new Scene(root);
        dessiner(canvas.getGraphicsContext2D());
        canvas.setOnMouseClicked(ev -> {
            points.add(new Point2D(ev.getX(), ev.getY()));
            dessiner(canvas.getGraphicsContext2D());
        });
        buttonOne.setOnAction(ev -> relierDernier(canvas.getGraphicsContext2D()));
        buttonFull.setOnAction(ev -> relierTous(canvas.getGraphicsContext2D()));
        primaryStage.setScene(scene);
        primaryStage.setResizable(false);
        primaryStage.show();
    }

    private void dessiner(GraphicsContext gc) {
        gc.setStroke(Color.BLACK);
        for (int i = 0; i < points.size(); i++) {
            final var p = points.get(i);
            gc.strokeText(i + "", p.getX(), p.getY());
        }
    }

    private void relierTous(GraphicsContext gc) {
        gc.setStroke(Color.BLACK);
        while (prevI < points.size() - 1) {
            var prevPoint = points.get(prevI);
            var nextPoint = points.get(++prevI);
            gc.strokeLine(prevPoint.getX(), prevPoint.getY(), nextPoint.getX(), nextPoint.getY());
        }
    }

    private void relierDernier(GraphicsContext gc) {
        gc.setStroke(Color.BLACK);
        if (prevI < points.size() - 1) {
            var prevPoint = points.get(prevI);
            var nextPoint = points.get(++prevI);
            gc.strokeLine(prevPoint.getX(), prevPoint.getY(), nextPoint.getX(), nextPoint.getY());
        }

    }
}
