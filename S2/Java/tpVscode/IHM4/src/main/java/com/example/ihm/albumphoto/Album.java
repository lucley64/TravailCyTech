package com.example.ihm.albumphoto;

import java.io.File;
import java.util.ArrayList;
import java.util.Observable;

public class Album extends Observable {

	public static final Integer CHANGEMENT_IMAGE_COURANTE = 0; // PAC
	public static final Integer CHANGEMENT_TAILLE = 1; // PAC
	public static final Integer NOUVELLE_IMAGE = 2; // PAC
	
	private ArrayList<Photo> lesPhotos; // biblioth�que d'images
	private int indexCourant; // index de l'image courante

	/**
	 * Initalise l'album en rajoutant les photos correspondantes a tous les
	 * fichiers du dossier repertoire
	 * 
	 * @param repertoire
	 *            le dossier contenant les photos de l'album
	 */
	public Album(String repertoire) {
		this.lesPhotos = new ArrayList<>();
		File repImages = new File(repertoire);
		for (String s : repImages.list()) {
			this.addPhoto("file:" + repertoire + "/" + s);
		}
		this.indexCourant = 0;
	}

	/**
	 * Retourne le nombre de photos dans l'album
	 * 
	 * @return le nombre de photos dans l'album
	 */
	public int getSize() {
		return this.lesPhotos.size();
	}

	/**
	 * Ajoute une photo dans l'album
	 * 
	 * @param fullpathname
	 *            chemin complet du fichier
	 */
	public void addPhoto(String fullpathname) {
		this.lesPhotos.add(new Photo(fullpathname));
		this.setChanged(); // PAC
		this.notifyObservers(NOUVELLE_IMAGE); // PAC
	}

	/**
	 * Retourne la photo d'index i si i est dans [0, this.getSize()[. Sinon,
	 * retourne null.
	 * 
	 * @return la photo d'index i si i est dans [0, this.getSize()[. Sinon,
	 *         retourne null.
	 * @param i
	 *            l'index de la photo a retourner
	 */
	public Photo getPhoto(int i) {
		if ((i < this.lesPhotos.size()) && (i >= 0)) {
			return this.lesPhotos.get(i);
		} else {
			return null;
		}
	}

	/**
	 * Retourne l'index de la photo courante de l'album
	 * 
	 * @return l'index de la photo courante de l'album
	 */
	public int getIndexCourant() {
		return this.indexCourant;
	}

	/**
	 * Modifie la photo courante
	 * 
	 * @param cindex
	 *            l'index de la photo qui devient la photo courante
	 */
	public void setIndexCourant(int cindex) {
		if ((cindex < this.lesPhotos.size()) && (cindex >= 0)) {
			this.indexCourant = cindex;
			this.setChanged(); // PAC
			this.notifyObservers(CHANGEMENT_IMAGE_COURANTE); // PAC
		}
	}

	/**
	 * Retourne la photo courante de l'album.
	 * 
	 * @return la photo courante de l'album.
	 */
	public Photo getPhotoCourante() {
		return this.lesPhotos.get(indexCourant);
	}

	/**
	 * redimensionne la photo courante de l'album avec zoom pour facteur de
	 * zoom.
	 * 
	 * @param zoom
	 *            le facteur de zoom a appliquer a la photo courante
	 */
	public void redimensionnerPhotoCourante(Float zoom) {
		this.getPhotoCourante().redimensionner(zoom);
		this.setChanged(); // PAC
		this.notifyObservers(CHANGEMENT_TAILLE); // PAC
	}

}