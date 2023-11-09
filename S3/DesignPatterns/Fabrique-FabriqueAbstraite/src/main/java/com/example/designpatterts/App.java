package com.example.designpatterts;

import java.util.List;

import com.example.designpatterts.factory.EnchantedMazeFactory;
import com.example.designpatterts.factory.MazeFactory;
import com.example.designpatterts.factory.MinedMazeFactory;
import com.example.designpatterts.factory.SimpleMazeFactory;

public class App {
    public static void main(String[] args) {
        List<MazeFactory> mazeFactories = List.of(new SimpleMazeFactory(), new EnchantedMazeFactory(), new MinedMazeFactory());
        CollectionUtils.select(mazeFactories, MazeFactory::create).forEach(System.out::println);
    }
}
