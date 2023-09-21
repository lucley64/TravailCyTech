package com.example.designpatterts.factory;

import maze.Maze;
import maze.door.Door;
import maze.room.Room;
import maze.room.Room.Direction;

public class SimpleMazeFactory extends MazeFactory {
    @Override
    public Maze create() {
        Room room1 = new Room(0);
        Room room2 = new Room(1);
        Door door = new Door(room1, room2);
        room1.setSide(Direction.SOUTH, door);
        room2.setSide(Direction.NORTH, door);

        Maze maze = new Maze();

        maze.addRoom(room1);
        maze.addRoom(room2);
        

        return maze;
    }
}
