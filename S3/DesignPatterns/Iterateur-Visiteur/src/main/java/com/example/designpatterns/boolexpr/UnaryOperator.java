package com.example.designpatterns.boolexpr;

public abstract class UnaryOperator implements Operator {

    protected Node operand;

    UnaryOperator(Node operand) {
        this.operand = operand;
    }

    public Node getOperand() {
        return operand;
    }


}
