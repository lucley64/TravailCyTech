package com.example.designpatterns.visitor;

import com.example.designpatterns.boolexpr.*;
import org.jetbrains.annotations.NotNull;

public class PrintVisitor implements BooleanExpressionWalker{

    private StringBuilder sb = new StringBuilder();

    @Override
    public void visit(@NotNull Node node) {
// none
    }

    @Override
    public void visit(@NotNull Operator operator) {
// none
    }

    @Override
    public void visit(@NotNull BinaryOperator binaryOperator) {
        //none
    }

    @Override
    public void visit(@NotNull UnaryOperator unaryOperator) {
        //none
    }

    @Override
    public void visit(@NotNull And and) {
        sb.append("AND");
    }

    @Override
    public void visit(@NotNull Bool bool) {
        sb.append(String.valueOf(bool.getValue()));
    }

    @Override
    public void visit(@NotNull Not not) {
        sb.append("NOT");
    }

    @Override
    public void visit(@NotNull Or or) {
        sb.append("OR");
    }

    @Override
    public String toString() {
        return sb.toString();
    }
}
