package com.example.designpatterns.visitor;

import com.example.designpatterns.boolexpr.And;
import com.example.designpatterns.boolexpr.Bool;
import com.example.designpatterns.boolexpr.Not;
import com.example.designpatterns.boolexpr.Or;
import org.jetbrains.annotations.NotNull;

public class EvaluateVisitor implements Visitor {
    boolean eval;


    @Override
    public void visit(@NotNull Bool bool) {
        eval = bool.getValue();
    }

    @Override
    public void visit(Not not) {
        not.getOperand().accept(this);
        eval = !eval;
    }

    @Override
    public void visit(Or or) {
        or.getLeftOperand().accept(this);
        boolean sav = eval;
        or.getRightOperand().accept(this);
        eval = sav || eval;
    }

    @Override
    public void visit(And and) {
        and.getLeftOperand().accept(this);
        boolean sav = eval;
        and.getRightOperand().accept(this);
        eval = sav && eval;
    }

    public boolean evaluate() {
        return eval;
    }
}
