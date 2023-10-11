package com.example.jee.mvc;

public enum Transportation {
    WALK,
    BIKE,
    CAR,
    BUS,
    TRAIN,
    PLANE;

    public static Transportation fromString(String str){
        return switch(str.toLowerCase()){
            case "walk" -> WALK;
            case "bike" -> BIKE;
            case "car" -> CAR;
            case "bus" -> BUS;
            case "train" -> TRAIN;
            case "place" -> PLANE;
            default -> null;
        };
    }
}
