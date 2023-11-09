package maze.door;

import maze.MapSite;
import maze.room.Room;

public class Door implements MapSite {

	private Room room1, room2;

	private boolean isOpen;

	public Door(Room room1, Room room2, boolean isOpen) {
		this.room1 = room1;
		this.room2 = room2;
		this.isOpen = isOpen;
	}

	public Door(Room room1, Room room2) {
		this(room1, room2, true);
	}
	
	public void enter() {
		if (!isOpen) {
			System.out.println("The door is locked.");
		}
	}

	public Room getRoom1() {
		return this.room1;
	}

	public Room getRoom2() {
		return this.room2;
	}

	public void setRooms(Room room1, Room room2) {
		this.room1 = room1;
		this.room2 = room2;
	}

	public boolean isOpen() {
		return this.isOpen;
	}
	
	public String toString() {
		return "door[" + getRoom1().getNumber() + "-" + getRoom2().getNumber() +"]";
	}

}
