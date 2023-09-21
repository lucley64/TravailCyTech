package maze.door;

import maze.room.Room;

public class MagicalDoor extends Door{
    public MagicalDoor(Room room1, Room room2, boolean isOpen){
        super(room1, room2, isOpen);
    }
    public MagicalDoor(Room room1, Room room2){
        super(room1, room2);
    }

    @Override
    public String toString() {
		return "magical door[" + getRoom1().getNumber() + "-" + getRoom2().getNumber() +"]";
	}
}
