package org.example.graphics3d;

import org.jetbrains.annotations.NotNull;

public abstract class Model {
    ModelMatrix modelMatrix;

    public Model(ModelMatrix modelMatrix) {
        this.modelMatrix = modelMatrix;
    }

    public ModelMatrix getModelMatrix() {
        return modelMatrix;
    }

    public void scale(float scale) {
        modelMatrix.scale(scale);
    }

    public void rotateX(float angle) {
        modelMatrix.rotateX(angle);
    }

    public void rotateY(float angle) {
        modelMatrix.rotateY(angle);
    }

    public void rotateZ(float angle) {
        modelMatrix.rotateZ(angle);
    }

    public void setRotationEulerAngle(Vec3 eulerAngle) {
        modelMatrix.setRotationEulerAngle(eulerAngle);
    }

    public void setRotationAngleAxis(Vec4 current) {
        modelMatrix.setRotationAngleAxis(current);
    }

    public void translate(Vec3 translation) {
        modelMatrix.translate(translation.getX(), translation.getY(), translation.getZ());
    }

    public void translate(float x, float y, float z) {
        modelMatrix.translate(x, y, z);
    }

    public void displayOrientation() {
        modelMatrix.displayOrientation();
    }

    public @NotNull Mat4 getRotationMatrix() {
        return modelMatrix.getRotationMatrix();
    }

}
