package com.example.designpatterns.boolexpr;

import com.example.designpatterns.visitor.Visitor;

public class And extends BinaryOperator {

    public And(Node leftOperand, Node rightOperand) {
        super(leftOperand, rightOperand);
    }

    @Override
    public boolean evaluate() {
        return leftOperand.evaluate() && rightOperand.evaluate();
    }

    @Override
    public String toString() {
        return leftOperand.toString() + " AND " + rightOperand.toString();
    }

    @Override
    public void accept(Visitor v) {
        v.visit(this);
    }
}
