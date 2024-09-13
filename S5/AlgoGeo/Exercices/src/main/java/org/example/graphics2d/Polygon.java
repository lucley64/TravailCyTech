package org.example.graphics;

import org.example.canvas.Drawable;

import java.awt.*;
import java.util.ArrayList;
import java.util.List;
import java.util.Objects;

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
}
