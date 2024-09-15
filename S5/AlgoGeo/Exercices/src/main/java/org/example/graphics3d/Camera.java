package org.example.graphics3d;

import org.jetbrains.annotations.NotNull;

public class Camera extends Model {
    public Camera(Vec3 position, Vec3 direction) {
        super(new ModelMatrix(
                1, 0, 0, 0,
                0, 1, 0, 0,
                0, 0, 1, 0,
                0, 0, 0, 1
        ));
        modelMatrix.getMatrix()[0][3] = position.getX();
        modelMatrix.getMatrix()[1][3] = position.getY();
        modelMatrix.getMatrix()[2][3] = position.getZ();

        setRotationEulerAngle(direction);

    }

    public Mat4 getCameraMatrix() {
        return modelMatrix;
    }

    public Mat4 getViewMatrix() {
        return modelMatrix.inverse();
    }
}
