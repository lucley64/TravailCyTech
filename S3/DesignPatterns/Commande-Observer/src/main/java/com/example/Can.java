package com.example;

public class Can {

	private int maxVolume;

	private int volume;

	public Can(int maxVolume) {
		this.maxVolume = maxVolume;
	}

	public int getVolume() {
		return this.volume;
	}

	public void setVolume(int volume) {
		this.volume = volume;
	}

	public int getMaxVolume() {
		return this.maxVolume;
	}

	public void empty() {
		this.setVolume(0);
	}

	public void fill() {
		this.setVolume(this.getMaxVolume());
	}

	public int decant(Can dest) {
		int decantedVolume = 0;
		int sum = this.getVolume() + dest.getVolume();
		if (sum > dest.getMaxVolume()) {
			decantedVolume = dest.getMaxVolume() - dest.getVolume();
			dest.setVolume(dest.getMaxVolume());
			this.setVolume(this.getVolume() - decantedVolume);
		} else {
			decantedVolume = this.getVolume();
			dest.setVolume(sum);
			this.empty();
		}
		return decantedVolume;
	}
	
	public String toString() {
		return "Bidon de " + this.getMaxVolume() + "L contenant " + this.getVolume() + "L d'eau";
	}
	
}
