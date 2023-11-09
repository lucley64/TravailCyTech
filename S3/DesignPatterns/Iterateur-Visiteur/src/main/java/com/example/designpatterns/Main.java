package com.example.designpatterns;

import com.example.designpatterns.boolexpr.*;
import com.example.designpatterns.tree.Tree;
import com.example.designpatterns.visitor.EvaluateVisitor;
import com.example.designpatterns.visitor.PrintVisitor;

public class Main {
    public static void main(String[] args) {
//        iterator();

        Node expression = new Not(new Or(new And(new Bool(true), new Bool(false)), new Bool(false)));

        PrintVisitor printVisitor = new PrintVisitor();

        expression.accept(printVisitor);

        System.out.println(printVisitor);

        EvaluateVisitor evaluateVisitor = new EvaluateVisitor();

        expression.accept(evaluateVisitor);

        System.out.println(evaluateVisitor.evaluate());

    }

    private static void iterator() {
        Tree<Integer> tree = new Tree<>(1, new Tree<>(2, new Tree<>(3, null, null), new Tree<>(4, null, null)), new Tree<>(5, null, null));

        for (var value : tree) {
            System.out.println(value);
        }
    }
}