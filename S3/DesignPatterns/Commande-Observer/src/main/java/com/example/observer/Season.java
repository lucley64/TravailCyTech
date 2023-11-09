package com.example.observer;

public enum Season {
    SPRING,
    SUMMER,
    AUTUMN,
    WINTER;

    public Season next(){
        Season ret = null;
        switch (this){
            case AUTUMN -> ret = Season.WINTER;
            case SPRING -> ret = Season.SUMMER;
            case SUMMER -> ret = Season.AUTUMN;
            case WINTER -> ret = Season.SPRING;
        }
        return ret;
    }
}
