package org.example.graphics2d;

import org.example.canvas.Canvas;
import org.example.canvas.MouseListener;
import org.example.canvas.PopupMenu;

import java.awt.event.MouseEvent;

public class MouseDraw extends MouseListener {
    private Polygon polygon;
    private final PopupMenu popupMenu;

    public MouseDraw(Canvas canvas, Polygon polygon) {
        super(canvas);
        this.polygon = polygon;
        this.popupMenu = new PopupMenu(canvas, polygon);
    }

    @Override
    protected void leftClickAction(MouseEvent e) {
        var newVertex = new Vertex(e.getX(), e.getY());
        getCanvas().addDrawable(newVertex);
        polygon.add(newVertex);
        getCanvas().repaint();
    }

    @Override
    protected void rightClickAction(MouseEvent e) {
        getCanvas().repaint();
        popupMenu.show(e.getComponent(), e.getX(), e.getY());
    }
}
