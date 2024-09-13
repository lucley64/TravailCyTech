package org.example.graphics3d;

import org.jetbrains.annotations.Contract;
import org.jetbrains.annotations.NotNull;

import java.util.Objects;

public class Vec3 {
    private float x;
    private float y;
    private float z;

    public Vec3() {
        x = y = z = 0;
    }

    public Vec3(float x, float y, float z) {
        this.x = x;
        this.y = y;
        this.z = z;
    }

    @Contract(pure = true)
    public Vec3(@NotNull Vec3 vec) {
        this.x = vec.x;
        this.y = vec.y;
        this.z = vec.z;
    }

    public Vec3 set(float x, float y, float z) {
        this.x = x;
        this.y = y;
        this.z = z;
        return this;
    }

    public Vec3 set(@NotNull Vec3 vec) {
        this.x = vec.x;
        this.y = vec.y;
        this.z = vec.z;
        return this;
    }

    public Vec3 add(@NotNull Vec3 vec) {
        return new Vec3(x + vec.x, y + vec.y, z + vec.z);
    }

    public Vec3 add(float x, float y, float z) {
        return new Vec3(this.x + x, this.y + y, this.z + z);
    }

    public Vec3 sub(@NotNull Vec3 vec) {
        return new Vec3(x - vec.x, y - vec.y, z - vec.z);
    }

    public Vec3 sub(float x, float y, float z) {
        return new Vec3(this.x - x, this.y - y, this.z - z);
    }

    public Vec3 mul(@NotNull Vec3 vec) {
        return new Vec3(this.x * vec.x, this.y * vec.y, this.z * vec.z);
    }

    public Vec3 mul(float x, float y, float z) {
        return new Vec3(this.x * x, this.y * y, this.z * z);
    }

    public Vec3 mul(float k) {
        return new Vec3(this.x * k, this.y * k, this.z * k);
    }

    public float length() {
        return (float) Math.sqrt(x * x + y * y + z * z);
    }

    public Vec3 normalize() {
        float len = length();
        return new Vec3(x / len, y / len, z / len);
    }

    public Vec3 negate() {
        return new Vec3(-x, -y, -z);
    }

    public float dot(@NotNull Vec3 vec) {
        return x * vec.x + y * vec.y + z * vec.z;
    }

    public Vec3 cross(@NotNull Vec3 vec) {
        return new Vec3(y * vec.z - z * vec.y, z * vec.x - x * vec.z, x * vec.y - y * vec.x);
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

    public Vec4 homogenous(){
        return new Vec4(x, y, z, 1);
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Vec3 vec3 = (Vec3) o;
        return Float.compare(x, vec3.x) == 0 && Float.compare(y, vec3.y) == 0 && Float.compare(z, vec3.z) == 0;
    }

    @Override
    public int hashCode() {
        return Objects.hash(x, y, z);
    }

    @Override
    public String toString() {
        return "Vec3{" + "x=" + x + ", y=" + y + ", z=" + z + '}';
    }

    public void print() {
        System.out.println(toString());
    }
}
