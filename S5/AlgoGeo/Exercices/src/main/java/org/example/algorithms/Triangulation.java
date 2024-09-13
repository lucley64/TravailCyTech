package org.example.algorithms;

import org.example.graphics2d.Line;
import org.example.graphics2d.Triangle;
import org.example.graphics2d.Vertex;
import org.jetbrains.annotations.NotNull;

import java.awt.*;
import java.util.*;
import java.util.List;

public class Triangulation {
    private Triangle firstTriangle;
    private Set<Triangle> triangles;
    private Set<Vertex> vertices;

    public Triangulation() {
        this.firstTriangle = null;
        this.triangles = new HashSet<>();
        this.vertices = new HashSet<>();
    }

    private Optional<Triangle> findTriangle(Vertex vertex) {
        return triangles.stream().filter(triangle -> triangle.isInside(vertex, Integer.MAX_VALUE)).findFirst();
    }

    private void legalizeEdge(Triangle triangle, Vertex vertex, Line edge, Graphics g) {
        if (!delaunayTest(edge, vertex, g)) {
            Triangle neighbour = triangle.getNeighborEdge(edge).get();
            var r = flip(triangle, neighbour, vertex, neighbour.otherVertex(edge), edge);
            legalizeEdge(r.a, vertex, r.edgeA, g);
            legalizeEdge(r.b, vertex, r.edgeB, g);
        }
    }

    private boolean delaunayTest(@NotNull Line line, Vertex vertex, Graphics g) {

        Vertex midpoint1 = new Line(line.getStart(), vertex).midpoint();
        midpoint1.draw(g);
        Vertex midpoint2 = new Line(line.getEnd(), vertex).midpoint();
        midpoint2.draw(g);

        Line perpendicular1 = new Line(line.getStart(), vertex).perpendicular();
        perpendicular1.draw(g);
        Line perpendicular2 = new Line(line.getEnd(), vertex).perpendicular();
        perpendicular2.draw(g);
        Vertex intersect = perpendicular1.intersection(perpendicular2);
        intersect.draw(g);
        double ag = new Line(line.getStart(), intersect).length();

        for (var v : vertices) {
            double ap = new Line(v, intersect).length();

            if (ap < ag) {
                midpoint2.clear(g);
                midpoint1.clear(g);
                perpendicular2.clear(g);
                perpendicular1.clear(g);
                intersect.clear(g);
                return false;
            }
        }
        midpoint2.clear(g);
        midpoint1.clear(g);
        perpendicular2.clear(g);
        perpendicular1.clear(g);
        intersect.clear(g);
        return true;
    }

    private static class ReturnFlip {
        public Triangle a;
        public Line edgeA;
        public Triangle b;
        public Line edgeB;
    }

    private @NotNull ReturnFlip flip(Triangle triangle, @NotNull Triangle neighbour, Vertex vertex, Vertex other, @NotNull Line edge) {
        triangles.remove(triangle);
        ReturnFlip returnFlip = new ReturnFlip();
        returnFlip.a = new Triangle(edge.getStart(), vertex, other, triangle.getNeighborEdge(new Line(edge.getStart(), vertex)).orElse(null), returnFlip.b, neighbour.getNeighborEdge(new Line(other, edge.getStart())).orElse(null));
        neighbour.updateNeighbor(returnFlip.a);
        returnFlip.edgeA = new Line(edge.getStart(), other);
        returnFlip.b = new Triangle(edge.getEnd(), vertex, other, triangle.getNeighborEdge(new Line(edge.getEnd(), vertex)).orElse(null), returnFlip.a, neighbour.getNeighborEdge(new Line(other, edge.getEnd())).orElse(null));
        neighbour.updateNeighbor(returnFlip.b);
        returnFlip.edgeB = new Line(edge.getEnd(), other);

        triangles.add(returnFlip.a);
        triangles.add(returnFlip.b);
        return returnFlip;
    }

    private void addPoint(Vertex vertex, Graphics g) {
        vertices.add(vertex);

        var triangle = findTriangle(vertex);

        if (triangle.isPresent()) {
            Triangle triangle1 = triangle.get();
            triangles.remove(triangle1);
            triangle1.clear(g);
            Triangle newTriangle1 = new Triangle(triangle1.getA(), triangle1.getB(), vertex, triangle1.getNeighborAB().orElse(null), null, null);
            triangle1.getNeighborAB().ifPresent(triangle2 -> triangle2.updateNeighbor(newTriangle1));
            newTriangle1.drawEdges(g);
            Triangle newTriangle2 = new Triangle(triangle1.getB(), triangle1.getC(), vertex, triangle1.getNeighborBC().orElse(null), null, newTriangle1);
            newTriangle1.setNeighborBC(newTriangle2);
            newTriangle2.drawEdges(g);
            triangle1.getNeighborBC().ifPresent(triangle2 -> triangle2.updateNeighbor(newTriangle2));
            Triangle newTriangle3 = new Triangle(triangle1.getC(), triangle1.getA(), vertex, triangle1.getNeighborCA().orElse(null), newTriangle1, newTriangle2);
            newTriangle1.setNeighborCA(newTriangle3);
            newTriangle2.setNeighborBC(newTriangle3);
            triangle1.getNeighborCA().ifPresent(triangle2 -> triangle2.updateNeighbor(newTriangle3));
            newTriangle3.drawEdges(g);
            triangles.add(newTriangle1);
            triangles.add(newTriangle2);
            triangles.add(newTriangle3);

            legalizeEdge(newTriangle1, vertex, new Line(triangle1.getA(), triangle1.getB()), g);
            legalizeEdge(newTriangle2, vertex, new Line(triangle1.getB(), triangle1.getC()), g);
            legalizeEdge(newTriangle3, vertex, new Line(triangle1.getC(), triangle1.getA()), g);
        }

    }

    public void naiveTriangulation(@NotNull Graphics g, List<Vertex> vertexList) {
        g.setColor(Color.red);
        Vertex origin = vertexList.getFirst();

        for (int i = 1; i < vertexList.size(); i++) {
            Triangle triangle = new Triangle(origin, vertexList.get(i), vertexList.get(i + 1));
        }
    }


}
