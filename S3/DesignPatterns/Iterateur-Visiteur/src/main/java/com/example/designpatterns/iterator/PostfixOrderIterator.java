package com.example.designpatterns.iterator;

import com.example.designpatterns.tree.Tree;

import java.util.Iterator;
import java.util.NoSuchElementException;
import java.util.Optional;

public class PostfixOrderIterator<T> implements Iterator<T> {
    private Optional<Tree<? extends T>> actual;


    public PostfixOrderIterator(Tree<? extends T> tree) {
        actual = Optional.ofNullable(tree);
        while (actual.isPresent() && actual.get().getLeft() != null){
            actual = Optional.of(actual.get().getLeft());
        }
    }

    @Override
    public boolean hasNext() {
        return actual.isPresent();
    }

    @Override
    public T next() throws NoSuchElementException{

        if (actual.isPresent()){
            T value = actual.get().getValue();

            var prev = actual.get();

            actual = Optional.ofNullable(actual.get().getParent());

            if (actual.isPresent() && actual.get().getRight() != null && !prev.equals(actual.get().getRight())){
                actual = Optional.of(actual.get().getRight());

                while (actual.get().getLeft() != null){
                    actual = Optional.of(actual.get().getLeft());
                }

            }

            return value;
        }

        throw new NoSuchElementException();
    }
}
