package com.example.designpatterns.boolexpr;

import com.example.designpatterns.visitor.Visitor;

public interface Node {

    boolean evaluate();

    void accept(Visitor v);
}
