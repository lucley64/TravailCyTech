package org.example.algorithms;

import org.example.graphics2d.Line;
import org.example.graphics2d.Vertex;
import org.jetbrains.annotations.NotNull;

import java.awt.*;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;

public class ConvexHullAlgorithms {
    public static void extremeEdges(@NotNull Graphics g, @NotNull List<Vertex> vertices) {
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

    public static void jarvisMarch(@NotNull Graphics g, @NotNull List<Vertex> vertices) {
        Color c = g.getColor();

        List<Vertex> verticesCopy = new ArrayList<>(vertices);
        Vertex first = vertices.stream().min(Comparator.comparingInt(Vertex::getY)).get();
        Vertex current = first;
        List<Line> linesSelected = new ArrayList<>();
        try {
            do {
                g.setColor(Color.red);
                current.draw(g);
                Vertex min = current;
                for (var vertex : verticesCopy) {
                    g.setColor(Color.red);
                    vertex.draw(g);
                    Line line = new Line(current, vertex);
                    line.draw(g);

                    if (verticesCopy.stream().allMatch(vertex1 -> line.crossProduct(vertex1) < 0) && vertex != first) {
                        min = vertex;
                    }
                    Thread.sleep(100);
                    g.setColor(Color.BLACK);
                    vertex.draw(g);
                    line.clear(g);
                }
                Line line = new Line(current, min);
                g.setColor(Color.BLACK);
                line.draw(g);
                current.draw(g);
                linesSelected.add(line);
                verticesCopy.remove(min);
                current = min;
            } while (current != first);
        } catch (InterruptedException e) {System.out.println(e.getMessage());}
        g.setColor(Color.black);
        linesSelected.forEach(line -> line.draw(g));
        g.setColor(c);
    }
}
