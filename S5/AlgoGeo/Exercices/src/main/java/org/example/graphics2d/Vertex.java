package org.example.graphics;

import org.example.canvas.Drawable;

import java.awt.*;
import java.util.Objects;

public class Vertex implements Drawable {
    private int x;
    private int y;

    public Vertex(int x, int y) {this.x = x;this.y = y;}
    public int getX() {return this.x;}
    public int getY() {return this.y;}
    public void setX(int x) {this.x = x;}
    public void setY(int y) {this.y = y;}

    @Override
    public void draw(Graphics g) {
        g.fillOval(this.getX() - 5, this.getY() - 5, 10, 10);
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Vertex vertex = (Vertex) o;
        return x == vertex.x && y == vertex.y;
    }

    @Override
    public int hashCode() {
        return Objects.hash(x, y);
    }

    public void clear(Graphics g) {
        Color c = g.getColor();
        g.setColor(Color.white);
        g.fillOval(this.getX() - 5, this.getY() - 5, 10, 10);
        g.setColor(c);
    }
}
