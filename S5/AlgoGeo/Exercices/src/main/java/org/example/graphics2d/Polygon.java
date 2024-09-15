package org.example.graphics2d;

import java.util.List;

public class Polygon extends Shape {

    public Polygon(List<Vertex> vertices) {
        super(vertices, 99);
    }

    public Polygon() {
        super();
    }

    @Override
    public void add(Vertex p) {
        super.add(p);
    }

    @Override
    public void remove(Vertex p) {
        super.remove(p);
    }

    public void removeLast() {vertices.removeLast();}
}
