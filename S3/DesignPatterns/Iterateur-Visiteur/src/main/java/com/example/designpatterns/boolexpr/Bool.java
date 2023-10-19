package com.example.designpatterns.boolexpr;

import com.example.designpatterns.visitor.Visitor;
import org.jetbrains.annotations.NotNull;

public class Bool implements Node {

    private final boolean value;

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
    public void accept(@NotNull Visitor v) {
        v.visit(this);
    }
}
