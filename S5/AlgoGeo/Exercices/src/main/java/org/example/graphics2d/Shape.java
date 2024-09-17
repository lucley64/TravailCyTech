package org.example.graphics2d;

import org.example.canvas.Drawable;

import java.awt.*;
import java.util.ArrayList;
import java.util.List;
import java.util.Objects;

public abstract class Shape implements Drawable {
    protected ArrayList<Vertex> vertices;
    private int size;

    protected Shape(List<Vertex> vertices, int size) {
        this.vertices = new ArrayList<>(vertices);
        this.size = size;
    }

    protected Shape() {
        vertices = new ArrayList<>();
        size = 0;
    }

    public List<Vertex> getVertices() {
        return vertices;
    }

    protected void add(Vertex p) {
        vertices.add(p);
    }

    protected void remove(Vertex p) {
        vertices.remove(p);
    }

    public void draw(Graphics g) {
        for (Vertex v : vertices) {
            v.draw(g);
        }
        g.fillPolygon(vertices.stream().mapToInt(Vertex::getX).toArray(), vertices.stream().mapToInt(Vertex::getY).toArray(), vertices.size());
    }

    public void drawEdges(Graphics g) {
        for (int i = 0; i < vertices.size(); i++) {
            new Line(vertices.get(i), vertices.get((i + 1) % vertices.size())).draw(g);
            vertices.get(i).draw(g);
            vertices.get((i + 1) % vertices.size()).draw(g);
        }
    }

    public void clear(Graphics g) {
        Color c = g.getColor();
        g.setColor(Color.white);
        draw(g);
        g.setColor(Color.black);
        vertices.forEach(v -> v.draw(g));
        g.setColor(c);
    }

    public void clearEdges(Graphics g) {
        Color c = g.getColor();
        g.setColor(Color.white);
        drawEdges(g);
        g.setColor(Color.black);
        vertices.forEach(v -> v.draw(g));
        g.setColor(c);
    }

    public boolean isConvex() {
        List<Integer> crossProducts = new ArrayList<>();
        for (int i = 0; i < vertices.size() - 1; i++) {
            Vertex one = vertices.get(i);
            Vertex two = vertices.get(i + 1);
            Vertex three = vertices.get((i + 2) % vertices.size());

            Line line = new Line(one, two);
            crossProducts.add(line.crossProduct(three));
        }

        boolean allPos = true;
        boolean allNeg = true;
        for(var crossProduct: crossProducts) {
            allPos &= crossProduct >= 0;
            allNeg &= crossProduct <= 0;
        }

        return allPos || allNeg;
    }

    public boolean isInside(Vertex vertex, int maxY) {
        if (isConvex()) {
            List<Integer> crossProducts = new ArrayList<>();
            for (int i = 0; i < vertices.size(); i++) {
                Vertex one = vertices.get(i);
                Vertex two = vertices.get((i + 1) % vertices.size());

                Line line = new Line(one, two);
                crossProducts.add(line.crossProduct(vertex));
            }

            boolean allPos = true;
            boolean allNeg = true;
            for(var crossProduct: crossProducts) {
                allPos &= crossProduct >= 0;
                allNeg &= crossProduct <= 0;
            }

            return allPos || allNeg;
        }
        else {
            Line line = new Line(vertex, new Vertex(vertex.getX(), maxY));

            int nbIntersect = 0;
            for (int i = 0; i < vertices.size(); i++) {
                Vertex one = vertices.get(i);
                Vertex two = vertices.get((i + 1) % vertices.size());

                Line linePoly = new Line(one, two);
                if (linePoly.intersects(line)){
                    nbIntersect++;
                }
            }
            return nbIntersect % 2 != 0;
        }
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Shape shape = (Shape) o;
        return Objects.equals(vertices, shape.vertices);
    }

    @Override
    public int hashCode() {
        return Objects.hashCode(vertices);
    }

    public boolean contain(Vertex vertex) {
        return vertices.contains(vertex);
    }
}
