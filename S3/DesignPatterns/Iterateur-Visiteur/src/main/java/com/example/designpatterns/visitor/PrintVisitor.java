package com.example.designpatterns.visitor;

import com.example.designpatterns.boolexpr.And;
import com.example.designpatterns.boolexpr.Bool;
import com.example.designpatterns.boolexpr.Not;
import com.example.designpatterns.boolexpr.Or;
import org.jetbrains.annotations.NotNull;

public class PrintVisitor implements Visitor {
    StringBuilder sj = new StringBuilder();


    @Override
    public void visit(@NotNull Bool bool) {
        sj.append(bool.getValue());
    }

    @Override
    public void visit(Not not) {
        sj.append("NOT(");
        not.getOperand().accept(this);
        sj.append(")");
    }

    @Override
    public void visit(Or or) {
        sj.append("(");
        or.getLeftOperand().accept(this);
        sj.append(" OR ");
        or.getRightOperand().accept(this);
        sj.append(")");
    }

    @Override
    public void visit(And and) {
        sj.append("(");
        and.getLeftOperand().accept(this);
        sj.append(" AND ");
        and.getRightOperand().accept(this);
        sj.append(")");
    }


    @Override
    public String toString() {
        return sj.toString();
    }
}
