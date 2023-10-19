package com.example.designpatterns.boolexpr;

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

}
