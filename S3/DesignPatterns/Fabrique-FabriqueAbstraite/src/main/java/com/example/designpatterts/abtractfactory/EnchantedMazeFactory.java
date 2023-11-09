package com.example.designpatterts.abtractfactory;

import maze.door.Door;
import maze.door.MagicalDoor;
import maze.room.EnchantedRoom;
import maze.room.Room;

public class EnchantedMazeFactory extends MazeFactory {
    @Override
    public Door createDoor(Room room1, Room room2) {
        return new MagicalDoor(room1, room2);
    }

    @Override
    public Room createRoom1() {
        return new EnchantedRoom(0);
    }

    @Override
    public Room createRoom2() {
        return new EnchantedRoom(1);
    }
}
