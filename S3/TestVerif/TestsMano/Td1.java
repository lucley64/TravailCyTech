public class Td1 {

    public static int[] triBicolore(int[] t) {
        int i;
        int iZero;
        i = 1;
        iZero = t.length - 1;
        while (i < iZero) {
            if (t[i] == 0) {
                t[i] = t[iZero];
                t[iZero] = 0;
                iZero--;
            }
            i++;
        }
        return t;
    }

    static int oddOrPos(int[] x) {
        // E f f e c t s : i f x== n u l l throw NullPointerException
        // else r e t u r n the number of elements i n x t h a t
        // are e i t h e r odd or p o s i t i v e ( or both )
        int count = 0;

        for (int i = 0; i < x.length; i++) {
            if (x[i] % 2 == 1 || x[i] > 0) {
                count++;
            }
        }
        return count;
    }
    // t e s t : x=[−3 , −2, 0 , 1 , 4]
    // Expected = 3

    static int findLast(int[] x, int y) {
        // E f f e c t s : I f x== n u l l throw NullPointerException
        // else r e t u r n the index of the l a s t element
        // i n x t h a t equals y .
        // I f no such element exists , r e t u r n −1
        for (int i = x.length - 1; i > 0; i--) {
            if (x[i] == y) {
                return i;
            }
        }
        return -1;
    }
    // t e s t : x =[2 , 3 , 5 ] ; y = 2
    // Expected = 0

    static int countPositive(int[] x) {
        // E f f e c t s : I f x== n u l l throw NullPointerException
        // else r e t u r n the number of
        // p o s i t i v e elements i n x .
        int count = 0;
        for (int i = 0; i < x.length; i++) {
            if (x[i] >= 0) {
                count++;
            }
        }
        return count;
    }
    // t e s t : x=[−4 , 2 , 0 , 2]
    // Expected = 2

    static final int ORIGIN_YEAR = 1980;

    static int zune(int days) {
        int year = ORIGIN_YEAR;
        while (days > 365) {
            if (isLeapYear(year)) {
                if (days > 366) {
                    days -= 366;
                    year += 1;
                }
            } else {
                days -= 365;
                year += 1;
            }
        }
        return year;
    }

    private static boolean isLeapYear(int year) {
        return year % 4 == 0;
    }
}
