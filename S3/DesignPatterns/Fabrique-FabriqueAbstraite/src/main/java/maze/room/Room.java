package maze.room;

import java.util.HashMap;
import java.util.Map;

import maze.MapSite;

public class Room implements MapSite {

	public enum Direction {
		NORTH, SOUTH, EAST, WEST;
		public Direction opposite() {
			if (this == NORTH) {
				return SOUTH;
			} else if (this == EAST) {
				return WEST;
			} else if (this == SOUTH) {
				return NORTH;
			} else {
				return EAST;
			}
		}
	}

	private Map<Direction, MapSite> mapsites;

	private int number;

	public Room(int number) {
		this.mapsites = new HashMap<Direction, MapSite>(4);
		this.number = number;
	}

	public void enter() {
		System.out.println("I enter in the " + this.toString());
	}

	public int getNumber() {
		return this.number;
	}

	public MapSite getSide(Direction direction) {
		return this.mapsites.get(direction);
	}

	public void setSide(Direction direction, MapSite mapSite) {
		this.mapsites.put(direction, mapSite);
	}

	public String toString() {
		String result = "room " + getNumber();
		for (Direction d : this.mapsites.keySet()) {
			if (this.mapsites.get(d) != null) {
				result += " " + d + ":";
				if (this.mapsites.get(d) instanceof Room) {
					result += "room " + ((Room) this.mapsites.get(d)).getNumber();
				} else {
					result += this.mapsites.get(d);
				}
			}
		}
		return result;
	}

}
