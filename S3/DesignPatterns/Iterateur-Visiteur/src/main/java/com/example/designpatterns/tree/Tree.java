package com.example.designpatterns.tree;


import java.util.Iterator;

import com.example.designpatterns.iterator.InfixOrderIterator;
import com.example.designpatterns.iterator.PostfixOrderIterator;
import com.example.designpatterns.iterator.PrefixOrderIterator;

public class Tree<V> implements Iterable<V> {

	private Tree<V> left, right, parent;
	private V value;

	public Tree(V value, Tree<V> left, Tree<V> right) {
		this.value = value;
		this.left = left;
		this.right = right;
		this.parent = null;
		if (this.left != null) {
			this.left.parent = this;
		}
		if (this.right != null) {
			this.right.parent = this;
		}
	}

	public Tree(V value) {
		this(value, null, null);
	}

	public Tree<V> getLeft() {
		return left;
	}

	public Tree<V> getRight() {
		return right;
	}

	public Tree<V> getParent() {
		return parent;
	}

	public V getValue() {
		return value;
	}

	public Iterator<V> iterator() {
		return new PostfixOrderIterator<>(this);
	}

}
