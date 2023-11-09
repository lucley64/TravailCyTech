package com.example.designpatterns.boolexpr;

import com.example.designpatterns.visitor.Visitor;

public class Not extends UnaryOperator {

    public Not(Node operand) {
        super(operand);
    }

    @Override
    public boolean evaluate() {
        return !operand.evaluate();
    }

    @Override
    public String toString() {
        return "NOT(" + operand.toString() + ")";
    }

    @Override
    public void accept(Visitor v) {
        v.visit(this);
    }
}
