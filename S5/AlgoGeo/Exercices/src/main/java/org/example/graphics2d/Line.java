package org.example.graphics2d;

import org.example.canvas.Drawable;
import org.jetbrains.annotations.NotNull;

import java.awt.*;
import java.util.Objects;

public class Line implements Drawable {
    private Vertex start;
    private Vertex end;

    public Line(Vertex start, Vertex end) {
        this.start = start;
        this.end = end;
    }

    public Vertex getStart() {
        return start;
    }

    public Vertex getEnd() {
        return end;
    }

    public void setStart(Vertex start) {
        this.start = start;
    }

    public void setEnd(Vertex end) {
        this.end = end;
    }

    @Override
    public void draw(Graphics g) {
        g.drawLine(start.getX(), start.getY(), end.getX(), end.getY());
    }

    public void clear(Graphics g) {
        Color c = g.getColor();
        g.setColor(Color.white);

        g.drawLine(start.getX(), start.getY(), end.getX(), end.getY());
        g.setColor(c);
    }

    public int crossProduct(@NotNull Vertex vertex) {
        return ((end.getX() - start.getX()) * (vertex.getY() - start.getY()) - (end.getY() - start.getY()) * (vertex.getX() - start.getX()));
    }

    public boolean intersects(@NotNull Line line) {
        Line line1 = this;
        Line line2 = line;
        Line line3 = new Line(end, start);
        Line line4 = new Line(line.end, line.start);
        int crossProduct1 = line1.crossProduct(line2.getStart());
        int crossProduct2 = line2.crossProduct(line3.getStart());
        int crossProduct3 = line3.crossProduct(line4.getStart());
        int crossProduct4 = line4.crossProduct(line1.getStart());

        return (crossProduct1 >= 0 && crossProduct2 >= 0 && crossProduct3 >= 0 && crossProduct4 >= 0) || (crossProduct1 < 0 && crossProduct2 < 0 && crossProduct3 < 0 && crossProduct4 < 0);
    }

    public Vertex midpoint() {
        return new Vertex((start.getX() + end.getX()) / 2, (start.getY() + end.getY()) / 2);
    }

    public Line perpendicular(){
        Vertex midpoint = midpoint();
        return perpendicular(midpoint);
    }

    public Line perpendicular(Vertex vertex) {
        double slope = (double) (end.getY() - start.getY()) / (end.getX() - start.getX());
        double perpSlope = -1 / slope;
        int delta = (int) length() * 2;
        return new Line(new Vertex(vertex.getX() + delta, (int) (vertex.getY() + perpSlope * delta)), new Vertex(midpoint().getX() - delta, (int) (midpoint().getY() - perpSlope * delta)));
    }

    public Line perpendicularA(Vertex vertex) {
        double slope = (double) (end.getY() - start.getY()) / (end.getX() - start.getX());
        double perpSlope = -1 / slope;
        int delta = (int) length() * 200;
        return new Line(new Vertex(vertex.getX(), vertex.getY()), new Vertex(midpoint().getX() - delta, (int) (midpoint().getY() - perpSlope * delta)));
    }

    public Vertex intersection(@NotNull Line line) {
        // Calculate the coefficients of the lines
        double dy1 = start.getY() - end.getY();
        double dx1 = end.getX() - start.getX();
        double dy2 = line.start.getY() - line.end.getY();
        double dx2 = line.end.getX() - line.start.getX();

        // Calculate the determinants
        double determinant = dy1 * dx2 - dy2 * dx1;

        // Check if lines are parallel
        if (determinant == 0) {
            return null; // Lines are parallel or coincident
        }

        // Calculate the constants
        double e = dy1 * start.getX() + dx1 * start.getY();
        double f = dy2 * line.start.getX() + dx2 * line.start.getY();

        // Calculate intersection coordinates
        double x = (dx2 * e - dx1 * f) / determinant;
        double y = (dy1 * f - dy2 * e) / determinant;

        return new Vertex((int) x,(int) y);
    }

    public double length() {
        return Math.sqrt(Math.pow(start.getX() - end.getX(), 2) + Math.pow(start.getY() - end.getY(), 2));
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Line line = (Line) o;
        return Objects.equals(start, line.start) && Objects.equals(end, line.end) ||
                Objects.equals(start, line.end) && Objects.equals(end, line.start);
    }

    @Override
    public int hashCode() {
        return Objects.hash(start, end);
    }
}
