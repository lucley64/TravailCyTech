package com.example.designpatterns.strategy;

public enum Attack {

	ROCK, PAPER, SCISSORS;

	public int compare(Attack a) {
		if (this == ROCK && a == SCISSORS) {
			return 1;
		} else if (this == SCISSORS && a == ROCK) {
			return -1;
		} else {
			return this.compareTo(a);
		}
	}

}
