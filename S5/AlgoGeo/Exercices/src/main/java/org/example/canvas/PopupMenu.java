package org.example.canvas;

import org.example.algorithms.ConvexHullAlgorithms;
import org.example.algorithms.Triangulation;
import org.example.graphics2d.Polygon;
import org.example.graphics2d.Vertex;

import javax.swing.*;

public class PopupMenu extends JPopupMenu {
    public PopupMenu(Canvas canvas, Polygon polygon) {
//        JMenuItem mouseContained = new JMenuItem("Is Mouse Contained");
//        mouseContained.addActionListener(e -> JOptionPane.showMessageDialog(canvas, "The mouse is " + (polygon.isInside(new Vertex(getLocation().x, getLocation().y), canvas.getHeight()) ? "inside" : "outside")));
//        mouseContained.disable();
//        add(mouseContained);
//        JMenuItem isPolygonConvex = new JMenuItem("Is Polygon Convex");
//        isPolygonConvex.addActionListener(e -> JOptionPane.showMessageDialog(canvas, "The polygon is " + (polygon.isConvex() ? "convex" : "concave")));
//        add(isPolygonConvex);
        JMenuItem item = new JMenuItem("Algorithm Extreme Edges");
        item.addActionListener(e -> ConvexHullAlgorithms.extremeEdges(canvas.getGraphics(), canvas.getDrawables().stream().filter(drawable -> drawable instanceof Vertex).map(drawable -> (Vertex) drawable).toList()));
        add(item);
        JMenuItem item2 = new JMenuItem("Jarvis's March");
        item2.addActionListener(e -> ConvexHullAlgorithms.jarvisMarch(canvas.getGraphics(), canvas.getDrawables().stream().filter(drawable -> drawable instanceof Vertex).map(drawable -> (Vertex) drawable).toList()));
        add(item2);
        JMenuItem item3 = new JMenuItem("Naive triangulation");
        item3.addActionListener(e -> new Triangulation().naiveTriangulation(canvas.getGraphics(), canvas.getDrawables().stream().filter(drawable -> drawable instanceof Vertex).map(drawable -> (Vertex) drawable).toList()));
        add(item3);
    }
}
