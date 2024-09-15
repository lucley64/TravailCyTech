package org.example.graphics3d;

import org.example.canvas.Drawable;

import java.awt.*;

public class ScreenTriangle implements Drawable {
    private Vec3 v0;
    private Vec3 v1;
    private Vec3 v2;
    private  boolean fill;
    private Color color;
    public ScreenTriangle(Vec3 v0, Vec3 v1, Vec3 v2, boolean fill, Color color) {
        this.v0 = v0;
        this.v1 = v1;
        this.v2 = v2;
        this.fill = fill;
        this.color = color;
    }
    public Vec3 getV0() {
        return v0;
    }
    public void setV0(Vec3 v0) {
        this.v0 = v0;
    }
    public Vec3 getV1() {
        return v1;
    }
    public void setV1(Vec3 v1) {
        this.v1 = v1;
    }
    public Vec3 getV2() {
        return v2;
    }
    public void setV2(Vec3 v2) {
        this.v2 = v2;
    }

    @Override
    public void draw(Graphics g) {
        Color c = g.getColor();
        if (fill) {
            g.setColor(color);
            g.fillPolygon(new int[]{(int) v0.getX(), (int) v1.getX(), (int) v2.getX()}, new int[]{(int) v0.getY(), (int) v1.getY(), (int) v2.getY()}, 3);
        }
        else {
            g.setColor(Color.BLACK);
            g.drawLine((int) v0.getX(), (int) v0.getY(), (int) v1.getX(), (int) v1.getY());
            g.drawLine((int) v1.getX(), (int) v1.getY(), (int) v2.getX(), (int) v2.getY());
            g.drawLine((int) v2.getX(), (int) v2.getY(), (int) v0.getX(), (int) v0.getY());
        }
        g.setColor(c);
    }
}
