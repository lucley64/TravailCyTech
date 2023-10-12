package com.example.designpatterns.boolexpr;

import com.example.designpatterns.visitor.BooleanExpressionWalker;

public interface Node {

    boolean evaluate();

    void accept(BooleanExpressionWalker visitor);

}
