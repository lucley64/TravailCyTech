package com.example.designpatterns;

import com.example.designpatterns.tree.Tree;

public class Main {
    public static void main(String[] args) {
        Tree<Integer> tree = new Tree<>(1, new Tree<>(2, new Tree<>(3, null, null), new Tree<>(4, null, null)), new Tree<>(5, null, null));

        for (var value : tree) {
            System.out.println(value);
        }
    }
}