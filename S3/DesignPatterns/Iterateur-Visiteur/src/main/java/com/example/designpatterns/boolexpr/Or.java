package com.example.designpatterns.boolexpr;

import com.example.designpatterns.visitor.BooleanExpressionWalker;

public class Or extends BinaryOperator {

	public Or(Node leftOperand, Node rightOperand) {
		super(leftOperand, rightOperand);
	}

	@Override
	public boolean evaluate() {
		return leftOperand.evaluate() || rightOperand.evaluate();
	}

	@Override
	public String toString() {
		return "(" + leftOperand.toString() + " OR " + rightOperand.toString() + ")";
	}

	@Override
	public void accept(BooleanExpressionWalker visitor) {
		visitor.visit(this);
	}
}
