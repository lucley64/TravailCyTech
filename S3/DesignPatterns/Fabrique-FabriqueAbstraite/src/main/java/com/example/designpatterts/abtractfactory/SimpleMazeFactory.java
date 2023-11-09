package com.example.designpatterts.abtractfactory;

import maze.door.Door;
import maze.room.Room;

public class SimpleMazeFactory extends MazeFactory{
    @Override
    public Door createDoor(Room room1, Room room2) {
        return new Door(room1, room2);
    }

    @Override
    public Room createRoom1() {
        return new Room(0);
    }

    @Override
    public Room createRoom2() {
        return new Room(1);
    }
}
