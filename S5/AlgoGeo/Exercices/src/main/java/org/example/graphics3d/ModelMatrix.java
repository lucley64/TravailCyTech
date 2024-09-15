package org.example.graphics3d;

import org.jetbrains.annotations.Contract;
import org.jetbrains.annotations.NotNull;

public class ModelMatrix extends Mat4 {
    public ModelMatrix() {
    }

    public ModelMatrix(float @NotNull [] @NotNull [] matrix) {
        super(matrix);
    }

    public ModelMatrix(@NotNull Mat4 matrix) {
        super(matrix);
    }

    public ModelMatrix(float a00, float a01, float a02, float a03, float a10, float a11, float a12, float a13, float a20, float a21, float a22, float a23, float a30, float a31, float a32, float a33) {
        super(a00, a01, a02, a03, a10, a11, a12, a13, a20, a21, a22, a23, a30, a31, a32, a33);
    }

    public void scale(float scale) {
        float[][] matrix = new float[][]{
                {scale, 0, 0, 0},
                {0, scale, 0, 0},
                {0, 0, scale, 0},
                {0, 0, 0, 1}
        };
        this.matrix = mul(new Mat4(matrix)).getMatrix();
    }

    public void rotateX(float angle) {
        float[][] matrix = new float[][]{
                {1, 0, 0, 0},
                {0, (float) Math.cos(angle), (float) -Math.sin(angle), 0},
                {0, (float) Math.sin(angle), (float) Math.cos(angle), 0},
                {0, 0, 0, 1}
        };
        this.matrix = mul(new Mat4(matrix)).getMatrix();
    }

    public void rotateY(float angle) {
        float[][] matrix = new float[][]{
                {(float) Math.cos(angle), 0, (float) Math.sin(angle), 0},
                {0, 1, 0, 0},
                {(float) -Math.sin(angle), 0, (float) Math.cos(angle), 0},
                {0, 0, 0, 1}
        };
        this.matrix = mul(new Mat4(matrix)).getMatrix();
    }

    public void rotateZ(float angle) {
        float[][] matrix = new float[][]{
                {(float) Math.cos(angle), (float) -Math.sin(angle), 0, 0},
                {(float) Math.sin(angle), (float) Math.cos(angle), 0, 0},
                {0, 0, 1, 0},
                {0, 0, 0, 1}
        };
        this.matrix = mul(new Mat4(matrix)).getMatrix();
    }

    public void setRotationEulerAngle(Vec3 eulerAngle) {
        var rotationMatrix = rotationMatrixFromEulerAngles(eulerAngle);
        var scalingFactor = Math.sqrt(
                this.matrix[0][0] * this.matrix[0][0]
                        + this.matrix[0][1] * this.matrix[0][1]
                        + this.matrix[0][2] * this.matrix[0][2]);
        Mat4 prev = new Mat4(matrix);
        this.matrix = rotationMatrix.getMatrix();
        scale((float) scalingFactor);
        translate(prev.getMatrix()[0][3], prev.getMatrix()[1][3], prev.getMatrix()[2][3]);

    }

    public void setRotationAngleAxis(Vec4 current) {
        var rotationMatrix = rotationMatrixFromAnglesAxis(current);
        var scalingFactor = Math.sqrt(
                this.matrix[0][0] * this.matrix[0][0]
                        + this.matrix[0][1] * this.matrix[0][1]
                        + this.matrix[0][2] * this.matrix[0][2]);
        Mat4 prev = new Mat4(matrix);
        this.matrix = rotationMatrix.getMatrix();
        scale((float) scalingFactor);
        translate(prev.getMatrix()[0][3], prev.getMatrix()[1][3], prev.getMatrix()[2][3]);
    }

    public void translate(float x, float y, float z) {
        this.matrix[0][3] += x;
        this.matrix[1][3] += y;
        this.matrix[2][3] += z;
    }

    public void displayOrientation() {

        var rotationMatrix = getRotationMatrix();

        System.out.println("Rotation matrix = " + rotationMatrix);

        Vec3 eulerAngles = eulerAnglesFromRotationMatrix(rotationMatrix);

        System.out.println("Euler angles = " + eulerAngles);

        var axisAngle = axisAngleFromRotationMatrix(rotationMatrix);

        System.out.println("Axis angle = " + axisAngle);
    }

    public @NotNull Mat4 getRotationMatrix() {
        var scalingFactor = Math.sqrt(
                this.matrix[0][0] * this.matrix[0][0]
                        + this.matrix[0][1] * this.matrix[0][1]
                        + this.matrix[0][2] * this.matrix[0][2]);

        var noTranslation = new Mat4(matrix);
        noTranslation.getMatrix()[0][3] = 0;
        noTranslation.getMatrix()[1][3] = 0;
        noTranslation.getMatrix()[2][3] = 0;

        return noTranslation.mul((float) (1f / scalingFactor));
    }

    public static @NotNull Vec3 eulerAnglesFromRotationMatrix(@NotNull Mat4 rotationMatrix) {
        var sy = Math.sqrt(
                rotationMatrix.getMatrix()[0][0] * rotationMatrix.getMatrix()[0][0] +
                        rotationMatrix.getMatrix()[1][0] * rotationMatrix.getMatrix()[1][0]);

        Vec3 eulerAngles;
        if (sy > 1e-6) {
            eulerAngles = new Vec3(
                    (float) Math.atan2(rotationMatrix.getMatrix()[2][1], rotationMatrix.getMatrix()[2][2]),
                    (float) Math.atan2(-rotationMatrix.getMatrix()[2][0], sy),
                    (float) Math.atan2(rotationMatrix.getMatrix()[1][0], rotationMatrix.getMatrix()[0][0])
            );
        } else {
            eulerAngles = new Vec3(
                    (float) Math.atan2(-rotationMatrix.getMatrix()[1][2], rotationMatrix.getMatrix()[1][1]),
                    (float) Math.atan2(-rotationMatrix.getMatrix()[2][0], sy),
                    0.0f
            );
        }
        return eulerAngles;
    }

    public static @NotNull Mat4 rotationMatrixFromEulerAngles(@NotNull Vec3 eulerAngles) {
        Mat4 rotationX = new Mat4(
                1, 0, 0, 0,
                0, (float) Math.cos(eulerAngles.getX()), (float) -Math.sin(eulerAngles.getX()), 0,
                0, (float) Math.sin(eulerAngles.getX()), (float) Math.cos(eulerAngles.getX()), 0,
                0, 0, 0, 1
        );
        Mat4 rotationY = new Mat4(
                (float) Math.cos(eulerAngles.getY()), 0, (float) Math.sin(eulerAngles.getY()), 0,
                0, 1, 0, 0,
                (float) -Math.sin(eulerAngles.getY()), 0, (float) Math.cos(eulerAngles.getY()), 0,
                0, 0, 0, 1
        );
        Mat4 rotationZ = new Mat4(
                (float) Math.cos(eulerAngles.getZ()), (float) -Math.sin(eulerAngles.getZ()), 0, 0,
                (float) Math.sin(eulerAngles.getZ()), (float) Math.cos(eulerAngles.getZ()), 0, 0,
                0, 0, 1, 0,
                0, 0, 0, 1
        );
        return rotationZ.mul(rotationY).mul(rotationX);
    }

    public static @NotNull Vec4 axisAngleFromRotationMatrix(@NotNull Mat4 rotationMatrix) {
        var epsilon = 1e-2f;
        var epsilon2 = 1e-1f;
        if ((Math.abs(rotationMatrix.getMatrix()[0][1] - rotationMatrix.getMatrix()[1][0]) < epsilon)
                && (Math.abs(rotationMatrix.getMatrix()[0][2] - rotationMatrix.getMatrix()[2][0]) < epsilon)
                && (Math.abs(rotationMatrix.getMatrix()[1][2] - rotationMatrix.getMatrix()[2][1]) < epsilon)) {
            // Singularity
            if ((Math.abs(rotationMatrix.getMatrix()[0][1] + rotationMatrix.getMatrix()[1][0]) < epsilon2)
                    && (Math.abs(rotationMatrix.getMatrix()[0][2] + rotationMatrix.getMatrix()[2][0]) < epsilon2)
                    && (Math.abs(rotationMatrix.getMatrix()[1][2] + rotationMatrix.getMatrix()[2][1]) < epsilon2)
                    && (Math.abs(rotationMatrix.getMatrix()[0][0] + rotationMatrix.getMatrix()[1][1] + rotationMatrix.getMatrix()[2][2] - 3) < epsilon2)) {
                // This singularity is identity matrix so angle = 0
                return new Vec4(1, 0, 0, 0); // zero angle, arbitrary axis
            }
            // Otherwise this singularity is angle = 180
            float angle = (float) Math.PI;
            float xx = (rotationMatrix.getMatrix()[0][0] + 1) / 2;
            float yy = (rotationMatrix.getMatrix()[1][1] + 1) / 2;
            float zz = (rotationMatrix.getMatrix()[2][2] + 1) / 2;
            float xy = (rotationMatrix.getMatrix()[0][1] + rotationMatrix.getMatrix()[1][0]) / 4;
            float xz = (rotationMatrix.getMatrix()[0][2] + rotationMatrix.getMatrix()[2][0]) / 4;
            float yz = (rotationMatrix.getMatrix()[1][2] + rotationMatrix.getMatrix()[2][1]) / 4;
            Vec3 axis;
            if ((xx > yy) && (xx > zz)) { // m[0][0] is the largest diagonal term
                if (xx < epsilon) {
                    axis = new Vec3(0, 0.7071f, 0.7071f);
                } else {
                    axis = new Vec3((float) Math.sqrt(xx), (float) (xy / Math.sqrt(xx)), (float) (xz / Math.sqrt(xx)));
                }
            } else if (yy > zz) { // m[1][1] is the largest diagonal term
                if (yy < epsilon) {
                    axis = new Vec3(0.7071f, 0, 0.7071f);
                } else {
                    axis = new Vec3((float) (xy / Math.sqrt(yy)), (float) Math.sqrt(yy), (float) (yz / Math.sqrt(yy)));
                }
            } else { // m[2][2] is the largest diagonal term so base result on this
                if (zz < epsilon) {
                    axis = new Vec3(0.7071f, 0.7071f, 0);
                } else {
                    axis = new Vec3((float) (xz / Math.sqrt(zz)), (float) (yz / Math.sqrt(zz)), (float) Math.sqrt(zz));
                }
            }
            return new Vec4(axis, angle); // return 180 deg rotation
        }
        Vec3 rotationAxis = new Vec3(
                rotationMatrix.getMatrix()[2][1] - rotationMatrix.getMatrix()[1][2],
                rotationMatrix.getMatrix()[0][2] - rotationMatrix.getMatrix()[2][0],
                rotationMatrix.getMatrix()[1][0] - rotationMatrix.getMatrix()[0][1]);

        var angle = Math.acos((rotationMatrix.trace(3) - 1) / 2);

        return new Vec4(rotationAxis, (float) angle);
    }


    @Contract("_ -> new")
    private @NotNull Mat4 rotationMatrixFromAnglesAxis(@NotNull Vec4 current) {
        float c = (float) Math.cos(current.getW());
        float s = (float) Math.sin(current.getW());
        float t = 1.0f - c;

        float m00 = c + current.getX() * current.getX() * t;
        float m11 = c + current.getY() * current.getY() * t;
        float m22 = c + current.getZ() * current.getZ() * t;


        float tmp1 = current.getX() * current.getY() * t;
        float tmp2 = current.getZ() * s;
        float m10 = tmp1 + tmp2;
        float m01 = tmp1 - tmp2;
        tmp1 = current.getX() * current.getZ() * t;
        tmp2 = current.getY() * s;
        float m20 = tmp1 - tmp2;
        float m02 = tmp1 + tmp2;
        tmp1 = current.getY() * current.getZ() * t;
        tmp2 = current.getX() * s;
        float m21 = tmp1 + tmp2;
        float m12 = tmp1 - tmp2;

        return new Mat4(
                m00, m01, m02, 0,
                m10, m11, m12, 0,
                m20, m21, m22, 0,
                0, 0, 0, 1);
    }

    public Vec3 eulerAnglesLERP(Vec3 v0, Vec3 v1, float t) {
        var x = (1 - t) * v0.getX() + t * v1.getX();
        var y = (1 - t) * v0.getY() + t * v1.getY();
        var z = (1 - t) * v0.getZ() + t * v1.getZ();
        return new Vec3(x, y, z);
    }

    public Vec4 anglesAxisLERP(Vec4 v0, Vec4 v1, float t) {
        var x = (1 - t) * v0.getX() + t * v1.getX();
        var y = (1 - t) * v0.getY() + t * v1.getY();
        var z = (1 - t) * v0.getZ() + t * v1.getZ();
        var w = (1 - t) * v0.getW() + t * v1.getW();
        return new Vec4(x, y, z, w);
    }
}
