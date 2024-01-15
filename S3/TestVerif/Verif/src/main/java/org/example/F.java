package org.example;

public class F {
    private F() {
    }

    /**
     * Returns index of maximum
     *
     * @param a an array
     * @return index of max
     */
    //@ requires a != null && a.length > 0;
    //@ ensures (0 <= \result < a.length) && \forall int i; 0<= i < a.length; a[\result] >= a[i];
    public static int f(int[] a) {
        int x = 0;
        int y = a.length - 1;
        //@ loop_invariant (0 <= x <= y < a.length) && (\forall int i; 0 <= i <= x || y <= i < a.length; a[i] <= a[x] || a[i] <= a[y]);
        while (x != y) {
            if (a[x] <= a[y]) {
                x++;
            } else {
                y--;
            }
        }
        return x;
    }
}
