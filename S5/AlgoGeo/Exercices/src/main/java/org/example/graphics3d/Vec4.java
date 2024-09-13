package org.example.graphics3d;

import org.jetbrains.annotations.Contract;
import org.jetbrains.annotations.NotNull;

public class Vec4 {
    private float x;
    private float y;
    private float z;
    private float w;

    public Vec4(float x, float y, float z, float w) {
        this.x = x;
        this.y = y;
        this.z = z;
        this.w = w;
    }

    @Contract(pure = true)
    public Vec4(@NotNull Vec4 vec) {
        this.x = vec.x;
        this.y = vec.y;
        this.z = vec.z;
        this.w = vec.w;
    }

    public Vec4(@NotNull Vec3 vec, float w) {
        this(vec.getX(), vec.getY(), vec.getZ(), w);
    }

    public float getX() {
        return x;
    }

    public void setX(float x) {
        this.x = x;
    }

    public float getY() {
        return y;
    }

    public void setY(float y) {
        this.y = y;
    }

    public float getZ() {
        return z;
    }

    public void setZ(float z) {
        this.z = z;
    }

    public float getW() {
        return w;
    }

    public void setW(float w) {
        this.w = w;
    }

    public Vec3 cartesian() {
        if (w == 0) {
            return new Vec3(x, y, z);
        }
        return new Vec3(x / w, y / w, z / w);
    }

    @Override
    public String toString() {
        return "Vec4{" +
                "x=" + x +
                ", y=" + y +
                ", z=" + z +
                ", w=" + w +
                '}';
    }

    public void print() {
        System.out.println(toString());
    }
}
