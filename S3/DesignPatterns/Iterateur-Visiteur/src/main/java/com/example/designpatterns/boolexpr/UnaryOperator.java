package com.example.designpatterns.boolexpr;

import com.example.designpatterns.visitor.BooleanExpressionWalker;

public abstract class UnaryOperator implements Operator {

	protected Node operand;

	UnaryOperator(Node operand) {
		this.operand = operand;
	}

	public Node getOperand() {
		return operand;
	}


	@Override
	public void accept(BooleanExpressionWalker visitor) {
		visitor.visit(this);
		visitor.visit(operand);
	}
}
