package com.example.ihm;

import java.util.ArrayList;
import java.util.List;

import com.example.ihm.albumphoto.Album;
import com.example.ihm.albumphoto.Photo;

import javafx.application.Application;
import javafx.beans.property.DoubleProperty;
import javafx.beans.property.ReadOnlyIntegerProperty;
import javafx.geometry.Orientation;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.ListView;
import javafx.scene.control.Menu;
import javafx.scene.control.MenuBar;
import javafx.scene.control.ScrollPane;
import javafx.scene.control.Slider;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.HBox;
import javafx.scene.layout.Pane;
import javafx.scene.layout.VBox;
import javafx.stage.Stage;

public class Visionneuse extends Application {

    private Album album = new Album("/home/cytech/Travail/S2/Java/tpVscode/IHM3/src/main/res/img");
    private ImageView iv;
    private Slider slider;
    private ListView lv;

    @Override
    public void start(Stage primaryStage) throws Exception {
        primaryStage.setTitle("Album photo");
        var menu = new Menu("Fichier");
        var menuBar = new MenuBar(menu);
        var prevButton = new Button("précédent");
        var nextButton = new Button("suivant");
        var hBoxButtons = new HBox(prevButton, nextButton);
        hBoxButtons.styleProperty().set("-fx-alignment: center ;");
        var image = creerCentre();
        slider = creerSlider();
        
        var hBoxPreview = creerBandeauBas();
        hBoxPreview.styleProperty().set("-fx-alignment: center ;");
        lv = creerListe();
        var bp = new BorderPane(image, hBoxButtons, slider, hBoxPreview, lv);
        var root = new VBox(menuBar, bp);
        var scene = new Scene(root);
        scene.getStylesheets().add("FILE:///home/cytech/Travail/S2/Java/tpVscode/IHM3/src/main/res/css/style.css");
        primaryStage.setScene(scene);
        primaryStage.show();
    }

    private ScrollPane creerCentre() {
        var pane = new ScrollPane();
        pane.setPrefSize(600, 450);
        iv = new ImageView(album.getPhotoCourante().getImage());
        pane.setContent(iv);
        return pane;
    }

    private Slider creerSlider() {
        var sl = new Slider(0, 300, 100);
        sl.setOrientation(Orientation.VERTICAL);
        sl.setShowTickLabels(true);
        sl.setShowTickMarks(true);
        sl.majorTickUnitProperty().set(100);
        sl.minorTickCountProperty().set(10);
        sl.valueProperty().addListener(l -> {
            album.redimensionnerPhotoCourante(((DoubleProperty) l).getValue().floatValue());
            setImageView(album.getPhotoCourante().getImage());
        });

        return sl;
    }

    private ListView<String> creerListe(){
        var listView = new ListView<String>();

        var list = new ArrayList<String>();
        for (var i = 0; i < album.getSize(); ++i){
            list.add(album.getPhoto(i).getNom());
        }

        listView.getItems().addAll(list);
        listView.getSelectionModel().selectedIndexProperty().addListener(l-> {
            var prop = (ReadOnlyIntegerProperty) l;
            album.setIndexCourant(prop.intValue());
            setImageView(album.getPhotoCourante().getImage());
            slider.valueProperty().set(album.getPhotoCourante().getZoom());
        });
        
        listView.getSelectionModel().select(0);
        
        return listView;
    }
    
    private void setImageView(Image img){
        if (iv != null){
            iv.setImage(img);
        }
    }

    private Pane creerBandeauBas(){
        var listB = new ArrayList<Button>();
        for (var i = 0; i < album.getSize(); ++i){
            var b = new Button("",new ImageView(album.getPhoto(i).getIcone()));
            b.setOnAction(ev -> {
                lv.getSelectionModel().select(listB.indexOf(b));
                listB.forEach(elem -> elem.getStyleClass().removeIf(eleme -> eleme.equals("active")));
                b.getStyleClass().add("active");
            });
            listB.add(b);
        }
        var hb = new HBox();
        hb.getChildren().addAll(listB);
        return hb;
    }

}
