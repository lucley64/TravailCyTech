package org.example.algorithms;

import org.example.graphics2d.Line;
import org.example.graphics2d.Shape;
import org.example.graphics2d.Triangle;
import org.example.graphics2d.Vertex;
import org.jetbrains.annotations.NotNull;

import java.awt.*;
import java.util.*;
import java.util.List;
import java.util.concurrent.atomic.AtomicBoolean;
import java.util.function.Predicate;

public class Triangulation {
    private class TriangleSet extends HashSet<Triangle> {
        public @NotNull Optional<Triangle> findTriangle(Vertex vertex) {
            return stream().filter(triangle -> triangle.isInside(vertex, Integer.MAX_VALUE)).findFirst();
        }

        public void updateNeighbours() {
            for (Triangle triangle : this) {
                for (Triangle otherTriangle : this) {
                    triangle.updateNeighbor(otherTriangle);
                }
            }
        }

        @Override
        public boolean remove(Object o) {
            if (super.remove(o)) {
                for (Triangle triangle : this) {
                    triangle.removeNeighbour((Triangle) o);
                }
                return true;
            }
            return false;
        }
    }

    private final TriangleSet triangles;
    private final Set<Vertex> vertices;

    public Triangulation() {
        this.triangles = new TriangleSet();
        this.vertices = new HashSet<>();
    }

    private boolean legalizeEdge(@NotNull Triangle trianglePrPiPj, Graphics g) {
        var trianglePiPjPk = trianglePrPiPj.getNeighborBC();
        var piPj = new Line(trianglePrPiPj.getB(), trianglePrPiPj.getC());
        AtomicBoolean ret = new AtomicBoolean(false);
        trianglePiPjPk.ifPresent(triangle -> {
            if (!delaunayTest(trianglePrPiPj, triangle.otherVertex(piPj), g)) {
                triangles.remove(triangle);
                triangle.clearEdges(g);
                triangles.remove(trianglePrPiPj);
                trianglePrPiPj.clearEdges(g);
                Triangle newTrianglePrPiPk = new Triangle(trianglePrPiPj.getA(), trianglePrPiPj.getB(), triangle.otherVertex(piPj));
                triangles.add(newTrianglePrPiPk);
                newTrianglePrPiPk.drawEdges(g);
                Triangle newTrianglePrPkPj = new Triangle(trianglePrPiPj.getA(), triangle.otherVertex(piPj), trianglePrPiPj.getC());
                triangles.add(newTrianglePrPkPj);
                newTrianglePrPkPj.drawEdges(g);
                triangles.updateNeighbours();
                legalizeEdge(newTrianglePrPiPk, g);
                legalizeEdge(newTrianglePrPkPj, g);
                ret.set(true);
            }
        });
        return ret.get();
    }

    private Optional<Vertex> delaunayTest(Triangle triangle, Graphics g) {
        for (Vertex vertex : vertices) {
            if (!triangle.contain(vertex) && delaunayTest(triangle, vertex, g)) {
                return Optional.of(vertex);
            }
        }
        return Optional.empty();
    }

    private boolean delaunayTest(@NotNull Triangle triangle, @NotNull Vertex vertex, Graphics g) {
        Line lineAB = new Line(triangle.getA(), triangle.getB());
        Line lineBC = new Line(triangle.getB(), triangle.getC());
        Vertex midpoint1 = lineAB.midpoint();
        midpoint1.draw(g);
        Vertex midpoint2 = lineBC.midpoint();
        midpoint2.draw(g);

        Line perpendicular1 = lineAB.perpendicular();
        perpendicular1.draw(g);
        Line perpendicular2 = lineBC.perpendicular();
        perpendicular2.draw(g);
        Vertex intersect = perpendicular1.intersection(perpendicular2);
        intersect.draw(g);
        double ag = new Line(triangle.getA(), intersect).length();
        vertex.draw(g);
        try {
            Thread.sleep(10);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        g.setColor(Color.black);
        vertex.draw(g);
        midpoint2.clear(g);
        midpoint1.clear(g);
        perpendicular2.clear(g);
        perpendicular1.clear(g);
        intersect.clear(g);
        g.setColor(Color.red);
        return new Line(vertex, intersect).length() > ag;
    }

    private void addPoint(Vertex vertex, Graphics g) {
        try {
            vertices.add(vertex);
            vertex.draw(g);
            Thread.sleep(10);
            var triangleP1P2P3 = triangles.findTriangle(vertex);
            if (triangleP1P2P3.isPresent()) {
                triangles.remove(triangleP1P2P3.get());
                triangleP1P2P3.get().clearEdges(g);
                Thread.sleep(10);
                Triangle trianglePP1P2 = new Triangle(vertex, triangleP1P2P3.get().getA(), triangleP1P2P3.get().getB());
                triangles.add(trianglePP1P2);
                trianglePP1P2.drawEdges(g);
                Thread.sleep(10);
                Triangle trianglePP2P3 = new Triangle(vertex, triangleP1P2P3.get().getB(), triangleP1P2P3.get().getC());
                triangles.add(trianglePP2P3);
                trianglePP2P3.drawEdges(g);
                Thread.sleep(10);
                Triangle trianglePP1P3 = new Triangle(vertex, triangleP1P2P3.get().getA(), triangleP1P2P3.get().getC());
                triangles.add(trianglePP1P3);
                trianglePP1P3.drawEdges(g);
                Thread.sleep(10);
                triangles.updateNeighbours();
                legalizeEdge(trianglePP1P2, g);
                Thread.sleep(10);
                legalizeEdge(trianglePP2P3, g);
                Thread.sleep(10);
                legalizeEdge(trianglePP1P3, g);
                Thread.sleep(10);
            }
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }

    private void lawsonFlip(@NotNull Triangle trianglePrPiPj, @NotNull Triangle trianglePiPjPk, Graphics g) {
        Line piPj = new Line(trianglePiPjPk.getA(), trianglePrPiPj.getB());
        if (delaunayTest(trianglePrPiPj, trianglePiPjPk.otherVertex(piPj), g)) {
            triangles.remove(trianglePiPjPk);
            triangles.remove(trianglePrPiPj);
            Triangle newTrianglePrPiPk = new Triangle(trianglePrPiPj.getA(), trianglePrPiPj.getB(), trianglePiPjPk.otherVertex(piPj));
            triangles.add(newTrianglePrPiPk);
            Triangle newTrianglePrPkPj = new Triangle(trianglePrPiPj.getA(), trianglePiPjPk.otherVertex(piPj), trianglePrPiPj.getC());
            triangles.add(newTrianglePrPkPj);
            triangles.updateNeighbours();
        }
    }

    public void slowDelaunay(@NotNull Graphics g, List<Vertex> vertexList) {
        naiveTriangulation(g, vertexList);

        boolean isChanged = true;
        while (isChanged) {
            for (Triangle triangle : triangles) {
                g.setColor(Color.red);
                triangles.forEach(triangle1 -> triangle1.clearEdges(g));
                isChanged = legalizeEdge(triangle, g);
                g.setColor(Color.red);
                triangles.forEach(triangle1 -> triangle1.drawEdges(g));
                try {
                    Thread.sleep(10);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
                if (isChanged) {
                    break;
                }
            }
        }

    }

    public void naiveTriangulation(@NotNull Graphics g, List<Vertex> vertexList) {
        g.setColor(Color.red);
        vertices.addAll(vertexList);
        List<Vertex> verticesCopy = new ArrayList<>(vertexList);
        Vertex first = vertexList.stream().min(Comparator.comparingInt(Vertex::getY)).get();
        verticesCopy.remove(first);
        verticesCopy.sort((o1, o2) -> {
            var line = new Line(first, o1);
            var line2 = new Line(first, o2);
            return Math.toIntExact(verticesCopy.stream().filter(vertex -> line.crossProduct(vertex) < 0).count()
                    - verticesCopy.stream().filter(vertex -> line2.crossProduct(vertex) < 0).count());
        });

        for (int i = 0; i < verticesCopy.size() - 1; i++) {
            Triangle triangle = new Triangle(verticesCopy.get(i), verticesCopy.get(i + 1), first);
            triangles.add(triangle);
            triangles.updateNeighbours();
        }

        triangles.forEach(triangle -> triangle.drawEdges(g));
    }


    public void incrementalDelaunay(@NotNull Graphics g, int height, int width, @NotNull List<Vertex> vertexList) {
        Vertex a = new Vertex(width / 2, 2 * height);
        Vertex b = new Vertex(-height, 0);
        Vertex c = new Vertex(width + height, 0);
        Triangle metaTriangle = new Triangle(a, b, c);
        triangles.add(metaTriangle);
        g.setColor(Color.red);
        metaTriangle.drawEdges(g);
        vertexList.forEach(vertex -> vertex.clear(g));

        for (Vertex vertex : vertexList) {
            addPoint(vertex, g);
        }

        triangles.forEach(triangle -> triangle.clearEdges(g));

        triangles.removeIf(triangle -> {
            if (triangle.contain(a) || triangle.contain(b) || triangle.contain(c)) {
                for (Triangle triangle1 : triangles) {
                    triangle1.removeNeighbour(triangle);
                }
                return true;
            }
            return false;
        });
        triangles.updateNeighbours();
        g.setColor(Color.black);
        triangles.forEach(triangle -> triangle.drawEdges(g));
    }

    public void voronoi(@NotNull Graphics g, int height, int width, @NotNull List<Vertex> vertexList) {
        incrementalDelaunay(g, height, width, vertexList);

//        triangles.forEach(triangle -> triangle.clearEdges(g));
//        vertexList.forEach(vertex -> vertex.clear(g));
        for (Triangle triangle : triangles) {
            Vertex cirumcenter = triangle.cirumcenter();
            cirumcenter.draw(g);
            if (triangle.getNeighborAB().isPresent()) {
                new Line(cirumcenter, triangle.getNeighborAB().get().cirumcenter()).draw(g);
            } else {
//                new Line(triangle.getA(), triangle.getB()).perpendicularA(cirumcenter).draw(g);
            }
            if (triangle.getNeighborBC().isPresent()) {
                new Line(cirumcenter, triangle.getNeighborBC().get().cirumcenter()).draw(g);
            } else {
//                new Line(triangle.getB(), triangle.getC()).perpendicularA(cirumcenter).draw(g);
            }
            if (triangle.getNeighborCA().isPresent()) {
                new Line(cirumcenter, triangle.getNeighborCA().get().cirumcenter()).draw(g);
            } else {
//                new Line(triangle.getC(), triangle.getA()).perpendicularA(cirumcenter).draw(g);
            }
        }
    }
}
