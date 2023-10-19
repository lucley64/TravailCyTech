package com.example.designpatterns.iterator;

import com.example.designpatterns.tree.Tree;

import java.util.Iterator;
import java.util.NoSuchElementException;
import java.util.Optional;

public class PrefixOrderIterator<T> implements Iterator<T> {

    private Optional<Tree<? extends T>> actual;


    public PrefixOrderIterator(Tree<? extends T> tree) {
        actual = Optional.ofNullable(tree);
    }

    @Override
    public boolean hasNext() {
        return actual.isPresent();
    }

    @Override
    public T next() throws NoSuchElementException {
        if (actual.isPresent()) {
            T value = actual.get().getValue();


            if (actual.get().getLeft() != null) {
                actual = Optional.of(actual.get().getLeft());
            } else if (actual.get().getRight() != null) {
                actual = Optional.of(actual.get().getRight());
            } else {
                var prev = actual.get();
                actual = Optional.ofNullable(actual.get().getParent());
                if (actual.isPresent() && actual.get().getRight() != null) {
                    while (actual.isPresent() && prev.equals(actual.get().getRight())) {
                        prev = actual.get();
                        actual = Optional.ofNullable(actual.get().getParent());
                    }
                    if (actual.isPresent()) {
                        actual = Optional.of(actual.get().getRight());
                    }
                }
            }


            return value;
        }

        throw new NoSuchElementException();
    }
}
