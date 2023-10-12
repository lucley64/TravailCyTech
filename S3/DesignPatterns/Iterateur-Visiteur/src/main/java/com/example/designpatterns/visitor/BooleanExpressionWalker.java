package com.example.designpatterns.visitor;

import com.example.designpatterns.boolexpr.*;
import org.jetbrains.annotations.NotNull;

public interface BooleanExpressionWalker {

    void visit(@NotNull Node node);

    void visit(@NotNull Operator operator);

    void visit(@NotNull BinaryOperator binaryOperator);

    void visit(@NotNull UnaryOperator unaryOperator);

    void visit(@NotNull And and);

    void visit(@NotNull Bool bool);

    void visit(@NotNull Not not);

    void visit(@NotNull Or or);

}
