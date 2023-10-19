package com.example.designpatterns.iterator;

import com.example.designpatterns.tree.Tree;
import org.jetbrains.annotations.NotNull;

import java.util.Iterator;
import java.util.NoSuchElementException;
import java.util.Optional;

public class InfixOrderIterator<T> implements Iterator<T> {

    private Optional<Tree<? extends T>> actual;


    public InfixOrderIterator(Tree<? extends T> tree) {
        actual = Optional.ofNullable(tree);
        while (actual.isPresent() && actual.get().getLeft() != null) {
            actual = Optional.of(actual.get().getLeft());
        }
    }

    @Override
    public boolean hasNext() {
        return actual.isPresent();
    }

    @Override
    public T next() throws NoSuchElementException {

        if (actual.isPresent()) {
            T value = actual.get().getValue();

            if (actual.get().getRight() != null) {
                moveRight(actual.get());
            } else {
                goBack(actual.get());
            }

            return value;
        }

        throw new NoSuchElementException();
    }

    private void moveRight(@NotNull Tree<? extends T> tree) {
        actual = Optional.of(tree.getRight());

        while (actual.get().getLeft() != null) {
            actual = Optional.of(actual.get().getLeft());
        }
    }

    private void goBack(@NotNull Tree<? extends T> tree) {
        if (tree.getParent() != null && tree.equals(tree.getParent().getRight())) {
            actual = Optional.ofNullable(tree.getParent().getParent());
            while (actual.isPresent() && actual.get().getParent() != null && actual.get().equals(actual.get().getParent().getRight())) {
                actual = Optional.ofNullable(actual.get().getParent().getParent());
            }
        } else {
            actual = Optional.ofNullable(tree.getParent());
        }
    }
}
