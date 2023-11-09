package com.example.designpatterts.factory;

import maze.Maze;
import maze.door.Door;
import maze.room.MinedRoom;
import maze.room.Room.Direction;
import maze.wall.CrackedWall;

public class MinedMazeFactory extends MazeFactory {
    @Override
    public Maze create() {
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
