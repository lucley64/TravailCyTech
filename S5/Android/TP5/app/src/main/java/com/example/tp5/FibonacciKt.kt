package com.example.tp5

fun fibonacciKt(n: UInt): ULong {
    tailrec fun fibonacci(n: UInt, a: ULong = 0U, b: ULong = 1U): ULong =
        when {
            n == 0U -> a
            n == 1U -> b
            a > ULong.MAX_VALUE - b -> throw Exception("Value out of range")
            else -> fibonacci(n - 1U, b, a + b)
        }
    return fibonacci(n)
}