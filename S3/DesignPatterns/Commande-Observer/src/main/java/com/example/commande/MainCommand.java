package com.example.commande;

import java.io.IOException;

public class MainCommand {
    static System.Logger logger = System.getLogger("mainLogger");
    public static void main(String[] args) throws IOException {
        Invoker invoker = new Invoker();
        Can can3L = new Can(3);
        Can can5L = new Can(5);

        while (can3L.getVolume() != 4 && can5L.getVolume() != 4){
            logger.log(System.Logger.Level.INFO, can3L + " and " + can5L);

            logger.log(System.Logger.Level.INFO, "Select your action (0: transfer, 1: fill, 2: empty, 3: undo)");
            var read = System.in.read();
            System.in.readNBytes(System.in.available());
            logger.log(System.Logger.Level.INFO, "Select source (0: Can 3L, 1: Can 5L)");
            var source = System.in.read();
            System.in.readNBytes(System.in.available());
            Can sourceCan;
            Can destCan;
            if (source == '0'){
                sourceCan = can3L;
                destCan = can5L;
            }
            else {
                sourceCan = can5L;
                destCan = can3L;
            }

            Command cmd = null;
            switch (read){
                case '0':
                    cmd = new Transfer(sourceCan, destCan);
                    break;
                case '1':
                    cmd = new Fill(sourceCan);
                    break;
                case '2':
                    cmd = new Empty(sourceCan);
                    break;
                default:break;
            }
            if (cmd == null){
                invoker.undo();
            }
            else {
                invoker.add(cmd);
            }
        }

        logger.log(System.Logger.Level.INFO, "Congrats");

    }
}