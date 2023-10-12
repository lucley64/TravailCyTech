package com.example.designpatterns.boolexpr;

public class Bool implements Node {

	private boolean value;

	public Bool(boolean value) {
		this.value = value;
	}

	public boolean getValue() {
		return value;
	}

}
