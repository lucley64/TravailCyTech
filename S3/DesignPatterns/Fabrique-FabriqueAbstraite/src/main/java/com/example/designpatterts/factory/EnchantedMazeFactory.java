package com.example.designpatterts.factory;

import maze.Maze;
import maze.door.MagicalDoor;
import maze.room.EnchantedRoom;
import maze.room.Room.Direction;

public class EnchantedMazeFactory extends MazeFactory {
    @Override
    public Maze create() {
        EnchantedRoom room1 = new EnchantedRoom(0);
        EnchantedRoom room2 = new EnchantedRoom(1);
        MagicalDoor door = new MagicalDoor(room1, room2);
        room1.setSide(Direction.SOUTH, door);
        room2.setSide(Direction.NORTH, door);

        Maze maze = new Maze();

        maze.addRoom(room1);
        maze.addRoom(room2);
        

        return maze;
    }
}
