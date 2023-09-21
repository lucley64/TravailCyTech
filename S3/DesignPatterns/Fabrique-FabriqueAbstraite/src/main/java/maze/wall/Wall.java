package maze.wall;

import maze.MapSite;

public class Wall implements MapSite {

	public void enter() {
		System.out.println("Ouch!");
	}

	public String toString() {
		return "wall";
	}

}
