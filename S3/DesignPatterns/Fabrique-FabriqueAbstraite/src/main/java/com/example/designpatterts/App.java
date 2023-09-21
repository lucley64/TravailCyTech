package com.example.designpatterts;

import java.util.List;

public class App {
    public static void main(String[] args) {
        var mazeCreator = new SimpleMazeGame();
        var maze = mazeCreator.createMaze();
        System.out.println(maze);
    }
}
