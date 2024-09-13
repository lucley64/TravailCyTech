package org.example.canvas;

import javax.swing.*;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;

public abstract class MouseListener extends MouseAdapter {
    private final Canvas canvas;

    protected MouseListener(@org.jetbrains.annotations.NotNull Canvas canvas) {
        super();
        this.canvas = canvas;
        canvas.addMouseListener(this);
    }

    public Canvas getCanvas() {
        return canvas;
    }

    @Override
    public void mouseClicked(MouseEvent e) {
        if (SwingUtilities.isLeftMouseButton(e)) {
            leftClickAction(e);
        }
        else{
            rightClickAction(e);
        }
        super.mouseClicked(e);
    }

    protected void rightClickAction(MouseEvent e) {

    }

    protected void leftClickAction(MouseEvent e) {

    }
}
