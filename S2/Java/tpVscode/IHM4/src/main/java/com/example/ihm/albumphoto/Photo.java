package com.example.ihm.albumphoto;



import java.io.File;

import javafx.scene.image.Image;

public class Photo {

	private final float ZOOM_MIN = 0.1f;
	private final float ZOOM_MAX = 5.0f;
	private final float ICON_SIZE = 80.0f;

	private String filename;
	private Image image;
	private int largeurInit;
	private int hauteurInit;
	private float zoom;
	private String nom;

	/**
	 * Constructeur initialisant la photo � partir du fichier image filename
	 * 
	 * @param filename
	 *            chemin complet du fichier image
	 */
	public Photo(String filename) {
		this.filename = filename;
		this.image = new Image(filename);
		this.largeurInit = this.getLargeur();
		this.hauteurInit = this.getHauteur();
		this.zoom = 1.0f;
		this.nom = (new File(filename)).getName();
		this.nom = this.nom.substring(0, this.nom.length() - 4);
	}

	/**
	 * Retourne l'image de la photo
	 * 
	 * @return l'image de la photo.
	 */
	public Image getImage() {
		return this.image;
	}

	/**
	 * Retourne la largeur de la photo
	 * 
	 * @return la largeur de la photo.
	 */
	public int getLargeur() {
		return (int) this.image.getWidth();
	}

	/**
	 * Retourne la hauteur de la photo
	 * 
	 * @return la hauteur de la photo.
	 */
	public int getHauteur() {
		return (int) this.image.getHeight();
	}

	/**
	 * Retourne le facteur de zoom
	 * 
	 * @return le facteur de zoom
	 */
	public int getZoom() {
		return ((int) (this.zoom * 100));
	}

	/**
	 * Retourne le nom de la photo
	 * 
	 * @return le nom de la photo
	 */
	public String getNom() {
		return this.nom;
	}

	/**
	 * Retourne une icone de la photo de dimension maximale ICON_SIZE
	 * 
	 * @return une icone de la photo de dimension maximale ICON_SIZE
	 */
	public Image getIcone() {
		float ratio = Math.max(this.largeurInit, this.hauteurInit);
		int largeur = (int) (ICON_SIZE * (float) this.largeurInit / ratio);
		int hauteur = (int) (ICON_SIZE * (float) this.hauteurInit / ratio);
		return new Image(this.filename, largeur, hauteur, false, false);
	}

	/**
	 * Redimensionne la photo en lui appliquant le facteur de zoom passe en
	 * parametre.
	 * 
	 * @param zoom
	 *            facteur de zoom du redimensionnement.
	 */
	public void redimensionner(float zoom) {
		this.zoom = Math.min(Math.max(zoom / 100, ZOOM_MIN), ZOOM_MAX);
		int largeur = (int) (this.largeurInit * this.zoom);
		int hauteur = (int) (this.hauteurInit * this.zoom);
		image = new Image(this.filename, largeur, hauteur, false, false);
	}
}
