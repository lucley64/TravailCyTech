package com.example.designpatterts.abtractfactory;

import java.util.List;

import maze.Maze;
import maze.door.Door;
import maze.room.Room;
import maze.room.Room.Direction;

public abstract class MazeFactory {
    public Maze create() {
        var room1 = createRoom1();
        var room2 = createRoom2();

        var door = createDoor(room1, room2);

        room1.setSide(Direction.SOUTH, door);
        room2.setSide(Direction.NORTH, door);

        Maze maze = new Maze();

        maze.addRoom(room1);
        maze.addRoom(room2);

        return maze;
    }

    public abstract Room createRoom1();

    public abstract Room createRoom2();

    public abstract Door createDoor(Room room1, Room room2);

    public static void main(String[] args) {
        List<MazeFactory> mazeFactories = List.of(new SimpleMazeFactory(), new EnchantedMazeFactory(),
                new MinedMazeFactory());
        mazeFactories.forEach(factory -> System.out.println(factory.create()));
    }
}
