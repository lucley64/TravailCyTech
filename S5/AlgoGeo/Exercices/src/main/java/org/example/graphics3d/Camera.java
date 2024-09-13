package org.example.graphics3d;

import org.jetbrains.annotations.NotNull;

public class Camera {
    Mat4 cameraMatrix;


    public Camera(Vec3 position, Vec3 direction) {
        cameraMatrix = new Mat4(
                1, 0, 0, 0,
                0, 1, 0, 0,
                0, 0, 1, 0,
                0, 0, 0, 1
        );
        cameraMatrix.getMatrix()[0][3] = position.getX();
        cameraMatrix.getMatrix()[1][3] = position.getY();
        cameraMatrix.getMatrix()[2][3] = position.getZ();

        setRotationEulerAngle(direction);

    }

    public Mat4 getCameraMatrix() {
        return cameraMatrix;
    }
    
    public Mat4 getViewMatrix() {
        return cameraMatrix.inverse();
    }

    public void scale(float scale) {
        float[][] matrix = new float[][]{
                {scale, 0, 0, 0},
                {0, scale, 0, 0},
                {0, 0, scale, 0},
                {0, 0, 0, 1}
        };
        cameraMatrix = cameraMatrix.mul(new Mat4(matrix));
    }

    public void rotateX(float angle) {
        float[][] matrix = new float[][]{
                {1, 0, 0, 0},
                {0, (float) Math.cos(angle), (float) -Math.sin(angle), 0},
                {0, (float) Math.sin(angle), (float) Math.cos(angle), 0},
                {0, 0, 0, 1}
        };
        cameraMatrix = cameraMatrix.mul(new Mat4(matrix));
    }

    public void rotateY(float angle) {
        float[][] matrix = new float[][]{
                {(float) Math.cos(angle), 0, (float) Math.sin(angle), 0},
                {0, 1, 0, 0},
                {(float) -Math.sin(angle), 0, (float) Math.cos(angle), 0},
                {0, 0, 0, 1}
        };
        cameraMatrix = cameraMatrix.mul(new Mat4(matrix));
    }

    public void rotateZ(float angle) {
        float[][] matrix = new float[][]{
                {(float) Math.cos(angle), (float) -Math.sin(angle), 0, 0},
                {(float) Math.sin(angle), (float) Math.cos(angle), 0, 0},
                {0, 0, 1, 0},
                {0, 0, 0, 1}
        };
        cameraMatrix = cameraMatrix.mul(new Mat4(matrix));
    }

    public void setRotationEulerAngle(Vec3 eulerAngle) {
        var rotationMatrix = rotationMatrixFromEulerAngles(eulerAngle);
        var scalingFactor = Math.sqrt(
                cameraMatrix.getMatrix()[0][0] * cameraMatrix.getMatrix()[0][0]
                        + cameraMatrix.getMatrix()[0][1] * cameraMatrix.getMatrix()[0][1]
                        + cameraMatrix.getMatrix()[0][2] * cameraMatrix.getMatrix()[0][2]);
        Mat4 prev = new Mat4(cameraMatrix);
        cameraMatrix = rotationMatrix;
        scale((float) scalingFactor);
        translate(prev.getMatrix()[0][3], prev.getMatrix()[1][3], prev.getMatrix()[2][3]);

    }

    public void translate(float x, float y, float z) {
        cameraMatrix.getMatrix()[0][3] += x;
        cameraMatrix.getMatrix()[1][3] += y;
        cameraMatrix.getMatrix()[2][3] += z;
    }

    public @NotNull Mat4 getRotationMatrix() {
        var scalingFactor = Math.sqrt(
                cameraMatrix.getMatrix()[0][0] * cameraMatrix.getMatrix()[0][0]
                        + cameraMatrix.getMatrix()[0][1] * cameraMatrix.getMatrix()[0][1]
                        + cameraMatrix.getMatrix()[0][2] * cameraMatrix.getMatrix()[0][2]);

        var noTranslation = new Mat4(cameraMatrix);
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
                    (float) Math.atan2(rotationMatrix.getMatrix()[2][0], sy),
                    (float) Math.atan2(rotationMatrix.getMatrix()[1][0], rotationMatrix.getMatrix()[0][0])
            );
        } else {
            eulerAngles = new Vec3(
                    (float) Math.atan2(rotationMatrix.getMatrix()[1][2], rotationMatrix.getMatrix()[1][1]),
                    (float) Math.atan2(rotationMatrix.getMatrix()[2][0], sy),
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


}
