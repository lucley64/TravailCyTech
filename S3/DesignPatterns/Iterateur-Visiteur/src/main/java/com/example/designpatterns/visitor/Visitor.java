package com.example.designpatterns.visitor;

import com.example.designpatterns.boolexpr.And;
import com.example.designpatterns.boolexpr.Bool;
import com.example.designpatterns.boolexpr.Not;
import com.example.designpatterns.boolexpr.Or;

public interface Visitor {

    void visit(Bool bool);

    void visit(Not not);

    void visit(Or or);

    void visit(And and);
}
