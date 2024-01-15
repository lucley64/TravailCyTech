package org.example;

public class Trie {
    private Trie(){}

    //@ requires t != null;
    //@ ensures (\forall int i; 1 <= i < t.length; t[i - 1] <= t[i]) <==> \result;
    public static boolean estTrie(int[] t) {
        //@ loop_invariant 1 <= i <= t.length;
        //@ loop_invariant \forall int j; 1 <= j < i; t[j - 1] <= t[j];
        //@ decreasing t.length - i;
        for (int i = 1; i < t.length; i++) {
            if (t[i] <= t[i - 1])
                return false;
        }
        return true;
    }
}
