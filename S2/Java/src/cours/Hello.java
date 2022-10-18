package src.cours;

import java.lang.System.Logger;
import java.lang.System.Logger.Level;

public class Hello {
    public static void main(String[] args) {
        Logger logger = System.getLogger("myLog");
        logger.log(Level.INFO, "Hello");
    }
}
