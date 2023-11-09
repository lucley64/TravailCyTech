package com.example.ihm.presentation;

import java.util.ArrayList;

import com.example.ihm.albumphoto.Album;
import com.example.ihm.controle.ControleBandeauBas;
import com.example.ihm.controle.ControleBoutonBas;
import com.example.ihm.controle.ControleBoutonPrecedent;
import com.example.ihm.controle.ControleBoutonSuivant;
import com.example.ihm.controle.ControleListe;
import com.example.ihm.controle.ControleMenu;
import com.example.ihm.controle.ControlePhotoCentre;
import com.example.ihm.controle.ControleSlider;

import javafx.application.Application;
import javafx.application.Platform;
import javafx.geometry.Orientation;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.ListView;
import javafx.scene.control.Menu;
import javafx.scene.control.MenuBar;
import javafx.scene.control.MenuItem;
import javafx.scene.control.ScrollPane;
import javafx.scene.control.SeparatorMenuItem;
import javafx.scene.control.Slider;
import javafx.scene.image.ImageView;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.HBox;
import javafx.scene.layout.Pane;
import javafx.scene.layout.VBox;
import javafx.stage.Stage;

public class Visionneuse extends Application {

    private Album album = new Album("/home/cytech/Travail/S2/Java/tpVscode/IHM3/src/main/res/img");

    @Override
    public void start(Stage primaryStage) throws Exception {
        primaryStage.setTitle("Album photo");
        var menuBar = creerMenu();
        var topPane = creerBandeauHaut();
        var image = creerCentre();
        var slider = creerSlider();
        var hBoxPreview = creerBandeauBas();
        hBoxPreview.styleProperty().set("-fx-alignment: center ;");
        var lv = creerListe();
        var bp = new BorderPane(image, topPane, slider, hBoxPreview, lv);
        var root = new VBox(menuBar, bp);
        var scene = new Scene(root);
        scene.getStylesheets().add("FILE:///home/cytech/Travail/S2/Java/tpVscode/IHM4/src/main/res/css/style.css");
        primaryStage.setScene(scene);
        primaryStage.show();
    }

    private ScrollPane creerCentre() {
        var pane = new ScrollPane();
        pane.setPrefSize(600, 450);
        var iv = new ImageView();
        var controlePhotoCentre = new ControlePhotoCentre(iv);
        album.addObserver(controlePhotoCentre);
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
        var controleSlider = new ControleSlider(sl, album);
        sl.valueProperty().addListener(controleSlider);
        album.addObserver(controleSlider);

        return sl;
    }

    private ListView<String> creerListe() {
        var listView = new ListView<String>();

        var list = new ArrayList<String>();
        for (var i = 0; i < album.getSize(); ++i) {
            list.add(album.getPhoto(i).getNom());
        }

        listView.getItems().addAll(list);

        var controleListe = new ControleListe(album, listView);
        listView.getSelectionModel().selectedIndexProperty().addListener(controleListe);
        album.addObserver(controleListe);

        listView.getSelectionModel().select(0);

        return listView;
    }

    private Pane creerBandeauBas() {
        var listB = new ArrayList<Button>();
        for (var i = 0; i < album.getSize(); ++i) {
            var b = new Button("", new ImageView(album.getPhoto(i).getIcone()));
            var controleBoutonBas = new ControleBoutonBas(album, b);
            b.setOnAction(controleBoutonBas);
            album.addObserver(controleBoutonBas);
            listB.add(b);
        }
        var hb = new HBox();
        hb.getChildren().addAll(listB);
        var controleBandeauBas = new ControleBandeauBas(hb);
        album.addObserver(controleBandeauBas);
        return hb;
    }

    private Pane creerBandeauHaut(){
        var prevButton = new Button("précédent");
        var controleBoutonPrecedent = new ControleBoutonPrecedent(prevButton, album);
        prevButton.setOnAction(controleBoutonPrecedent);
        album.addObserver(controleBoutonPrecedent);
        var nextButton = new Button("suivant");
        var controleBoutonSuivant = new ControleBoutonSuivant(nextButton, album);
        nextButton.setOnAction(controleBoutonSuivant);
        album.addObserver(controleBoutonSuivant);
        var hBoxButtons = new HBox(prevButton, nextButton);
        hBoxButtons.styleProperty().set("-fx-alignment: center ;");
        return hBoxButtons;
    }

    private MenuBar creerMenu(){
        var add = new MenuItem("Ajouter une photo");
        var controleMenu = new ControleMenu(album);
        add.setOnAction(controleMenu);
        var sep = new SeparatorMenuItem();
        var quit = new MenuItem("Quitter");
        quit.setOnAction(ev -> Platform.exit());
        var menu = new Menu("Fichier", null, add, sep, quit);
        
        
        return new MenuBar(menu);
    }

}
