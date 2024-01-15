package org.example;


public class Min {
    private Min(){}

    //@ ensures \forall int i; 0 <= i < t.length; \result <= t[i];
    //@ ensures \exists int i; 0 <= i < t.length; \result == t[i];
    //@ requires t != null && 0 < t.length;
    public static int getMin(int[] t) {
        int res = t[0];
        //@ loop_invariant 0 <= i && i <= t.length;
        //@ loop_invariant \forall int j; 0 <= j < i; res <= t[j];
        //@ loop_invariant \exists int j; 0 <= j < i; res == t[j];
        //@ decreasing t.length - i;
        for (int i = 1; i < t.length; i++)
            if (t[i] < res) res = t[i];
        return res;
    }
}
