package com.example.tp5;

public class FibonacciJv {
    public static long fibonacci(int n) throws Exception {
        return fibonacci(n, 0, 1);
    }

    private static long fibonacci(int n, long a, long b) throws Exception {
        if (a <= Long.MAX_VALUE - b){
            switch (n) {
                case 0:
                    return a;
                case 1:
                    return b;
                default:
                    return fibonacci(n - 1, b, a + b);
            }
        }
        else {
            throw new Exception("Value out of range");
        }
    }
}
