package com.example.designpatterts;

import maze.Maze;
import maze.door.Door;
import maze.door.MagicalDoor;
import maze.room.EnchantedRoom;
import maze.room.MinedRoom;
import maze.room.Room;
import maze.room.Room.Direction;
import maze.wall.CrackedWall;

public class SimpleMazeGame {
    public Maze createMaze(){
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

    public Maze createEnchantedMaze(){
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

    public Maze createMinedMaze(){
        MinedRoom room1 = new MinedRoom(0);
        MinedRoom room2 = new MinedRoom(1);
        Door door = new Door(room1, room2);
        CrackedWall crackedWall = new CrackedWall();
        room1.setSide(Direction.NORTH, crackedWall);
        room1.setSide(Direction.SOUTH, door);
        room2.setSide(Direction.NORTH, door);


        Maze maze = new Maze();

        maze.addRoom(room1);
        maze.addRoom(room2);
        

        return maze;
    }
}
