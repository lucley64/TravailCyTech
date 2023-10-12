package com.example.designpatterns.boolexpr;

import com.example.designpatterns.visitor.BooleanExpressionWalker;

public abstract class BinaryOperator implements Operator {

	protected Node leftOperand;
	protected Node rightOperand;

	BinaryOperator(Node leftOperand, Node rightOperand) {
		this.leftOperand = leftOperand;
		this.rightOperand = rightOperand;
	}

	public Node getLeftOperand() {
		return leftOperand;
	}

	public Node getRightOperand() {
		return rightOperand;
	}

	@Override
	public void accept(BooleanExpressionWalker visitor) {
		visitor.visit(leftOperand);
		visitor.visit(this);
		visitor.visit(rightOperand);
	}
}
