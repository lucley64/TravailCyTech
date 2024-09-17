package org.example.graphics2d;

import org.jetbrains.annotations.NotNull;

import java.util.*;

public class Triangle extends Shape {
    private Triangle neighborAB;
    private Triangle neighborBC;
    private Triangle neighborCA;

    public Triangle(@NotNull Triangle triangle) {
        this(triangle.getA(), triangle.getB(), triangle.getC(), triangle.neighborAB, triangle.neighborBC, triangle.neighborCA);
    }

    public Triangle(Vertex a, Vertex b, Vertex c) {
        this(a, b, c, null, null, null);
    }

    public Triangle(Vertex a, Vertex b, Vertex c, Triangle neighborAB, Triangle neighborBC, Triangle neighborCA) {
        super(Arrays.asList(a, b, c), 3);
        this.neighborAB = neighborAB;
        this.neighborBC = neighborBC;
        this.neighborCA = neighborCA;
    }

    public void setA(Vertex a) {
        vertices.set(0, a);
    }

    public void setB(Vertex b) {
        vertices.set(1, b);
    }

    public void setC(Vertex c) {
        vertices.set(2, c);
    }

    public Vertex getA() {
        return vertices.getFirst();
    }

    public Vertex getB() {
        return vertices.get(1);
    }

    public Vertex getC() {
        return vertices.get(2);
    }

    public Optional<Triangle> getNeighborAB() {
        return Optional.ofNullable(neighborAB);
    }

    public void setNeighborAB(Triangle neighborAB) {
        this.neighborAB = neighborAB;
    }

    public Optional<Triangle> getNeighborBC() {
        return Optional.ofNullable(neighborBC);
    }

    public void setNeighborBC(Triangle neighborBC) {
        this.neighborBC = neighborBC;
    }

    public Optional<Triangle> getNeighborCA() {
        return Optional.ofNullable(neighborCA);
    }

    public void setNeighborCA(Triangle neighborCA) {
        this.neighborCA = neighborCA;
    }

    public Optional<Triangle> getNeighborEdge(@NotNull Line edge){
        if(edge.getStart() == getA()){
            if(edge.getEnd() == getB()){
                return getNeighborAB();
            }
            else if(edge.getEnd() == getC()){
                return getNeighborBC();
            }
        }
        else if(edge.getStart() == getB()){
            if(edge.getEnd() == getA()){
                return getNeighborAB();
            }
            else if(edge.getEnd() == getC()){
                return getNeighborBC();
            }
        }
        else if(edge.getStart() == getC()){
            if(edge.getEnd() == getB()){
                return getNeighborBC();
            }
            else if(edge.getEnd() == getA()){
                return getNeighborCA();
            }
        }
        return Optional.empty();
    }

    public boolean hasLine(Line line){
        return Objects.equals(line, new Line(getA(), getB())) || Objects.equals(line, new Line(getB(), getC())) || Objects.equals(line, new Line(getC(), getA()));
    }

    public void updateNeighbor(@NotNull Triangle neighbor){
        if (neighbor != this) {
            if (neighbor.hasLine(new Line(getA(), getB()))) {
                setNeighborAB(neighbor);
            }
            else if (neighbor.hasLine(new Line(getB(), getC()))) {
                setNeighborBC(neighbor);
            }
            else if (neighbor.hasLine(new Line(getC(), getA()))) {
                setNeighborCA(neighbor);
            }
        }
    }

    public void removeNeighbour(Triangle neighbor){
        if (neighborAB != null && neighborAB.equals(neighbor)) {
            setNeighborAB(null);
        }
        else if (neighborBC != null && neighborBC.equals(neighbor)) {
            setNeighborBC(null);
        }
        else if (neighborCA != null && neighborCA.equals(neighbor)) {
            setNeighborCA(null);
        }
    }

    public Vertex otherVertex(Line edge){
        if(edge.getStart().equals(getA())){
            if(edge.getEnd().equals(getB())){
                return getC();
            }
            else if(edge.getEnd().equals(getC())){
                return getB();
            }
        }
        else if(edge.getStart().equals(getB())){
            if(edge.getEnd().equals(getA())){
                return getC();
            }
            else if(edge.getEnd().equals(getC())){
                return getA();
            }
        }
        else if(edge.getStart().equals(getC())){
            if(edge.getEnd().equals(getA())){
                return getB();
            }
            else if(edge.getEnd().equals(getB())){
                return getA();
            }
        }
        return null;
    }


    public Vertex cirumcenter() {
        Line lineAB = new Line(getA(), getB());
        Line lineBC = new Line(getB(), getC());

        Line perpendicular1 = lineAB.perpendicular();
        Line perpendicular2 = lineBC.perpendicular();
        return perpendicular1.intersection(perpendicular2);
    }
}
