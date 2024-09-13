package org.example.graphics3d;

import org.example.canvas.Canvas;
import org.jetbrains.annotations.NotNull;

import java.lang.Thread;
import java.util.List;

public class Scene {
    private final Camera camera;
    private final Mat4 projectionMatrix;
    private final Mat4 perspectiveProjectionMatrix;
    private final Mat4 viewMatrix;
    private TriangleMesh triangleMesh = null;
    private boolean usesPerspective;

    public Scene(Mat4 projectionMatrix, Mat4 perspectiveProjectionMatrix, Mat4 viewMatrix, Camera camera, boolean usesPerspective) {
        this.projectionMatrix = projectionMatrix;
        this.perspectiveProjectionMatrix = perspectiveProjectionMatrix;
        this.viewMatrix = viewMatrix;
        this.camera = camera;
        this.usesPerspective = usesPerspective;
    }

    public Camera getCamera() {
        return camera;
    }

    public boolean isUsesPerspective(){
        return usesPerspective;
    }

    public void setUsesPerspective(boolean usesPerspective){
        this.usesPerspective = usesPerspective;
    }

    public Mat4 getProjectionMatrix() {
        return projectionMatrix;
    }

    public Mat4 getViewMatrix() {
        return viewMatrix;
    }

    public void render(Canvas canvas) {
        var vertices = List.of(
                new Vec3(-0.5f, 0.0f, 0.5f),
                new Vec3(-0.5f, 0.0f, -0.5f),
                new Vec3(0.5f, 0.0f, -0.5f),
                new Vec3(0.5f, 0.0f, 0.5f),
                new Vec3(0.0f, 0.8f, 0.0f));

        var indices = List.of(
                List.of(0, 1, 2),
                List.of(0, 2, 3),
                List.of(0, 1, 4),
                List.of(1, 2, 4),
                List.of(2, 3, 4),
                List.of(3, 0, 4)
        );
        float[][] modelMatrix = new float[][]{
                {100, 0, 0, 0},
                {0, 100, 0, 0},
                {0, 0, 100, 0},
                {0, 0, 0, 1}
        };
        triangleMesh = new TriangleMesh(vertices, indices, new Mat4(modelMatrix));

        rerender(canvas);
    }

    public void rerender(@NotNull Canvas canvas) {
        canvas.clearDrawables();

        List<ScreenTriangle> triangles;
        if (usesPerspective) {
            triangles = triangleMesh.renderToScreen(perspectiveProjectionMatrix, viewMatrix, camera.getViewMatrix());
        }
        else {
            triangles = triangleMesh.renderToScreen(projectionMatrix, viewMatrix, camera.getViewMatrix());
        }

        triangles.forEach(canvas::addDrawable);
    }

    public void scale(float scale) {
        triangleMesh.scale(scale);
    }

    public void rotateX(float angle) {
        triangleMesh.rotateX((float) ((angle * Math.PI) / 180));
    }

    public void rotateY(float angle) {
        triangleMesh.rotateY((float) ((angle * Math.PI) / 180));
    }

    public void rotateZ(float angle) {
        triangleMesh.rotateZ((float) ((angle * Math.PI) / 180));
    }

    public void translate(float x, float y, float z) {
        triangleMesh.translate(x, y, z);
    }

    public void printRotation() {
        triangleMesh.displayOrientation();
    }

    public void resetRotationEulerAngles(Canvas canvas) {
        new Thread(() -> {
            var rot = triangleMesh.getRotationMatrix();
            var orig = TriangleMesh.eulerAnglesFromRotationMatrix(rot);
            var dest = new Vec3(0, 0, 0);
            for (float i = 0.0f; i <= 1.0f; i += 0.01f) {
                var current = triangleMesh.eulerAnglesLERP(orig, dest, i);
                triangleMesh.setRotationEulerAngle(current);
                rerender(canvas);
                try {
                    Thread.sleep(10);
                } catch (InterruptedException e) {
                    throw new RuntimeException(e);
                }
            }
        }).start();
    }

    public void resetRotationExponentialMap() {

        new Thread(() -> {
            var rot = triangleMesh.getRotationMatrix();
            var orig = TriangleMesh.axisAngleFromRotationMatrix(rot);
            var dest = new Vec4(1, 0, 0, 0);
            for (float i = 0.0f; i <= 1.0f; i += 0.01f) {
                var current = triangleMesh.anglesAxisLERP(orig, dest, i);
                triangleMesh.setRotationAngleAxis(current);
                rerender(canvas);
                try {
                    Thread.sleep(10);
                } catch (InterruptedException e) {
                    throw new RuntimeException(e);
                }
            }
        }).start();
    }

    public void resetRotationEulerQuaternion() {
    }

}
