package com.example.designpatterts.abtractfactory;

import maze.door.Door;
import maze.room.MinedRoom;
import maze.room.Room;
import maze.room.Room.Direction;
import maze.wall.CrackedWall;

public class MinedMazeFactory extends MazeFactory {
    @Override
    public Door createDoor(Room room1, Room room2) {
        return new Door(room1, room2);
    }

    @Override
    public Room createRoom1() {
        var room = new MinedRoom(0);
        room.setSide(Direction.NORTH, new CrackedWall());
        return room;
    }

    @Override
    public Room createRoom2() {
        return new MinedRoom(1);
    }
}
