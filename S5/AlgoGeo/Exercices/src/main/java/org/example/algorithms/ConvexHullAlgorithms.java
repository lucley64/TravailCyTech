package org.example.algorithms;

import org.example.graphics.Line;
import org.example.graphics.Polygon;
import org.example.graphics.Vertex;
import org.jetbrains.annotations.NotNull;

import java.awt.*;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

public class ExtremeEdges {
    public static void draw(Graphics g, @NotNull List<Vertex> vertices) {
        Color c = g.getColor();
        List<Line> linesDone = new ArrayList<>();

        try{
            for (var vertex : vertices) {
                g.setColor(Color.red);
                vertex.draw(g);
                g.setColor(c);
                Thread.sleep(100);
                List<Vertex> verticesCopy = new ArrayList<>(vertices);
                verticesCopy.remove(vertex);
                for (var vertexOther : verticesCopy) {
                    Line line = new Line(vertex, vertexOther);
                    if (!linesDone.contains(line)) {
                        g.setColor(Color.red);
                        vertex.draw(g);
                        line.draw(g);
                        g.setColor(c);
                        Thread.sleep(100);
                        List<Vertex> verticesOtherCopy = new ArrayList<>(verticesCopy);
                        verticesOtherCopy.remove(vertexOther);
                        boolean allPos = true;
                        boolean allNeg = true;
                        for (var otherVertex : verticesOtherCopy) {
                            g.setColor(Color.red);
                            vertex.draw(g);
                            g.setColor(c);
                            Thread.sleep(100);
                            int crossProduct = line.crossProduct(otherVertex);
                            allPos &= crossProduct >= 0;
                            allNeg &= crossProduct <= 0;
                            vertex.draw(g);
                        }
                        if (allPos || allNeg) {
                            g.setColor(Color.black);
                        }
                        else {
                            g.setColor(Color.white);
                        }
                        line.draw(g);
                        g.setColor(c);

                        linesDone.add(line);
                    }
                    vertex.draw(g);
                }
                vertex.draw(g);
            }
        } catch (InterruptedException e) {System.out.println(e.getMessage());}
        g.setColor(c);
    }
}
