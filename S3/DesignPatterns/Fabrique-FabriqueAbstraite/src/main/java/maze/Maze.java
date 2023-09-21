package maze;

import java.util.ArrayList;
import java.util.List;

import maze.room.Room;

public class Maze {

	private List<Room> rooms;

	public Maze() {
		this.rooms = new ArrayList<Room>();
	}

	public void addRoom(Room room) {
		this.rooms.add(room);
	}

	public Room roomNo(int number) {
		for (Room room : rooms) {
			if (room.getNumber() == number) {
				return room;
			}
		}
		return null;
	}

	public String toString() {
		String str = "Maze with " + rooms.size() + " room"
				+ (rooms.size() > 1 ? "s" : "") + ":\n";
		for (Room room : rooms) {
			str += "- " + room + "\n";
		}
		return str;
	}

}
