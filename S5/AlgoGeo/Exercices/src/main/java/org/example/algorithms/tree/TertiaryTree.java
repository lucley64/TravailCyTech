package org.example.algorithms.tree;


public class TertiaryTree<T> {
    public T root;
    public TertiaryTree<T> left = null;
    public TertiaryTree<T> middle = null;
    public TertiaryTree<T> right = null;
    public TertiaryTree(T root) {this.root = root;}
}

