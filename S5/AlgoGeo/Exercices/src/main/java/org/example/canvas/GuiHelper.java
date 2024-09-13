package org.example.canvas;

import javax.swing.*;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

public class GuiHelper {

    private GuiHelper() {
    }

    public static void showOnFrame(JComponent component, String name) {
        JFrame frame = new JFrame(name);
        WindowAdapter windowAdapter = new WindowAdapter() {
            @Override
            public void windowClosing(WindowEvent e) {
                System.exit(0);
            }
        };
        frame.addWindowListener(windowAdapter);
        frame.getContentPane().add(component);
        frame.pack();
        frame.setVisible(true);
    }
}
