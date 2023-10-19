package com.example.designpatterns.adapter;

import org.jetbrains.annotations.NotNull;

import java.util.Iterator;

public class Utils {

    public static void printChars(@NotNull Iterator<Object> elems) {
        while (elems.hasNext()) {
            var elem = elems.next();
            if (elem instanceof CharSequence str) {
                System.out.println(str);
            }
        }
    }


}
