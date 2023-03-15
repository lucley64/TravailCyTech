package com.example;

import java.util.Arrays;

/**
 * Retourne le jour de la semaine correspondant au num
 * 
 * @author moi
 * @version 1.0
 */
public enum JourSemaine {
    DIMANCHE(0),
    LUNDI(1),
    MARDI(2),
    MERCREDI(3),
    JEUDI(4),
    VENDREDI(5),
    SAMEDI(6);

    private final int index;

    public int getIndex() {
        return index;
    }

    @Override
    public String toString() {
        return Arrays.stream(JourSemaine.class.getEnumConstants()).map(Enum::name).toArray(String[]::new)[index];
    }

    public static JourSemaine fromIndex(int index) {
        switch (index) {
            case 0:
                return DIMANCHE;
            case 1:
                return LUNDI;
            case 2:
                return MARDI;
            case 3:
                return MERCREDI;
            case 4:
                return JEUDI;
            case 5:
                return VENDREDI;
            case 6:
                return SAMEDI;
            default:
                throw new IndexOutOfBoundsException(index);
        }
    }

    public static JourSemaine fromDate(int day, int month, int year) {
        var j = day;
        var mm = (month > 2) ? month - 2 : month + 10;
        var aa = (month > 2) ? year % 100 : (year - 1) % 100;
        var ss = (month > 2) ? year / 100 : (year - 1) / 100;

        var ha = (((13 * mm - 1) / 5) + j + aa + aa / 4 + ss / 4 - 2 * ss);
        var index = Math.floorMod(ha, 7);
        return fromIndex(index);
    }

    JourSemaine(int index) {
        this.index = index;
    }
}
