package com.example.ihm;

import java.util.List;

import com.example.ihm.albumphoto.Album;
import com.example.ihm.albumphoto.Photo;

import javafx.application.Application;
import javafx.beans.property.DoubleProperty;
import javafx.geometry.Orientation;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.ListView;
import javafx.scene.control.Menu;
import javafx.scene.control.MenuBar;
import javafx.scene.control.Slider;
import javafx.scene.image.ImageView;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.HBox;
import javafx.scene.layout.StackPane;
import javafx.scene.layout.VBox;
import javafx.stage.Stage;

public class Visionneuse extends Application{

    private Album album = new Album("/home/cytech/Travail/S2/Java/tpVscode/IHM3/src/main/res/img");

    @Override
    public void start(Stage primaryStage) throws Exception {
        primaryStage.setTitle("Album photo");
        var menu = new Menu("Fichier");
        var menuBar = new MenuBar(menu);
        var prevButton = new Button("précédent");
        var nextButton = new Button("suivant");
        var hBoxButtons = new HBox(prevButton, nextButton);
        hBoxButtons.styleProperty().set("-fx-alignment: center ;");
        var lv = new ListView<String>();
        lv.getItems().addAll("foo", "bar");
        var image = creerCentre();
        var zoom = creerSlider();
        var buttonImg = new Button("dummy");
        var hBoxPreview = new HBox(buttonImg);
        hBoxPreview.styleProperty().set("-fx-alignment: center ;");
        var bp = new BorderPane(image, hBoxButtons, zoom, hBoxPreview, lv);
        var root = new VBox(menuBar, bp);
        var scene = new Scene(root);
        primaryStage.setScene(scene);
        primaryStage.show();
    }
    
    private StackPane creerCentre(){
        var pane = new StackPane();
        pane.setPrefSize(600, 450);
        pane.getChildren().add(new ImageView(album.getPhotoCourante().getImage()));
        return pane;
    }
    
    private Slider creerSlider(){
        var slider = new Slider(0, 300, 100);
        slider.setOrientation(Orientation.VERTICAL);
        slider.setShowTickLabels(true);
        slider.setShowTickMarks(true);
        slider.majorTickUnitProperty().set(100);
        slider.minorTickCountProperty().set(10);
        slider.valueProperty().addListener(l -> {
            
        });
        
        return slider;
    }
    
}
