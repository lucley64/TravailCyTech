package com.example.designpatterns.boolexpr;

import com.example.designpatterns.visitor.BooleanExpressionWalker;

public class Not extends UnaryOperator {

	public Not(Node operand) {
		super(operand);
	}

	@Override
	public boolean evaluate() {
		return ! operand.evaluate();
	}

	@Override
	public String toString() {
		return "NOT(" + operand.toString() + ")";
	}

	@Override
	public void accept(BooleanExpressionWalker visitor) {
		visitor.visit(this);
		visitor.visit(operand);
	}
}
