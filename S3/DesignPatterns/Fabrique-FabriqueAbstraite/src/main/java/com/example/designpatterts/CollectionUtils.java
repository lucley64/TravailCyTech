package com.example.designpatterts;

import java.util.ArrayList;
import java.util.Collection;
import java.util.List;
import java.util.function.Function;

public class CollectionUtils {
    public static <T, Y> Collection<Y> select(Iterable<T> collection, Function<? super T, Y> function) {
        List<Y> result = new ArrayList<>();
        for (T item : collection) {
            result.add(function.apply(item));
        }
        return result;
    }

    public static <T, Y> Collection<Y> selectMany(Iterable<T> collection, Function<? super T, Collection<Y>> function) {
        List<Y> res = new ArrayList<>();
        for (T item : collection) {
            res.addAll(function.apply(item));
        }
        return res;
    }
}
