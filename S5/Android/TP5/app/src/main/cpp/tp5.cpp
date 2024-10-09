// Write C++ code here.
//
// Do not forget to dynamically load the C++ library into your application.
//
// For instance,
//
// In MainActivity.java:
//    static {
//       System.loadLibrary("tp5");
//    }
//
// Or, in MainActivity.kt:
//    companion object {
//      init {
//         System.loadLibrary("tp5")
//      }
//    }

#include <jni.h>

unsigned long fibonacci(unsigned int n, unsigned long a = 0, unsigned long b = 1);

extern "C"
JNIEXPORT jlong JNICALL
Java_com_example_tp5_MainActivity_fibonacci(JNIEnv *, jobject, jint n) {
    unsigned long res = fibonacci(n);
    return res;
}

unsigned long fibonacci(unsigned int n, unsigned long a, unsigned long b) { // NOLINT(*-no-recursion)
    switch (n) {
        case 0:
            return a;
        case 1:
            return b;
        default:
            return fibonacci(n - 1, b, a + b);
    }
}