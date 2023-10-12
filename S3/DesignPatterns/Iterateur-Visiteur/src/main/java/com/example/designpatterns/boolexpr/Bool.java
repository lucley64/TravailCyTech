package com.example.designpatterns.boolexpr;

import com.example.designpatterns.visitor.BooleanExpressionWalker;

public class Bool implements Node {

	private boolean value;

	public Bool(boolean value) {
		this.value = value;
	}

	public boolean getValue() {
		return value;
	}

	@Override
	public boolean evaluate() {
		return value;
	}

	@Override
	public String toString() {
		return String.valueOf(value);
	}

	@Override
	public void accept(BooleanExpressionWalker visitor) {
		visitor.visit(this);

	}
}
