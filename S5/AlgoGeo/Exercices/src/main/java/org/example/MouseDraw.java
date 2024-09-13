package org.example;

import org.example.canvas.Canvas;
import org.example.canvas.MouseListener;
import org.example.canvas.PopupMenu;
import org.example.graphics2d.Polygon;
import org.example.graphics2d.Vertex;

import java.awt.event.MouseEvent;

public class MouseDraw extends MouseListener {
    private Polygon polygon;
    private PopupMenu popupMenu;
    protected MouseDraw(Canvas canvas, Polygon polygon) {super(canvas); this.polygon = polygon; this.popupMenu = new PopupMenu(canvas, polygon); }

    @Override
    protected void leftClickAction(MouseEvent e) {
        getCanvas().addDrawable(new Vertex(e.getX(), e.getY()));
        getCanvas().repaint();
    }

    @Override
    protected void rightClickAction(MouseEvent e) {
        getCanvas().repaint();
        popupMenu.show(e.getComponent(), e.getX(), e.getY());
    }
}
