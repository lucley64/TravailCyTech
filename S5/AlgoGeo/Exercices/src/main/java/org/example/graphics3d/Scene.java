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
    private final Light light;
    private boolean usesPerspective;
    private boolean isWireFrame;
    private boolean useBackfaceCulling;

    public Scene(Mat4 projectionMatrix, Mat4 perspectiveProjectionMatrix, Mat4 viewMatrix, Camera camera, boolean usesPerspective, boolean isWireFrame, Light light, boolean useBackfaceCulling) {
        this.projectionMatrix = projectionMatrix;
        this.perspectiveProjectionMatrix = perspectiveProjectionMatrix;
        this.viewMatrix = viewMatrix;
        this.camera = camera;
        this.usesPerspective = usesPerspective;
        this.isWireFrame = isWireFrame;
        this.light = light;
        this.useBackfaceCulling = useBackfaceCulling;
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

    public boolean isWireFrame() {
        return isWireFrame;
    }

    public void setWireFrame(boolean wireFrame) {
        isWireFrame = wireFrame;
    }

    public boolean isUseBackfaceCulling() {
        return useBackfaceCulling;
    }

    public void setUseBackfaceCulling(boolean useBackfaceCulling) {
        this.useBackfaceCulling = useBackfaceCulling;
    }

    public Mat4 getProjectionMatrix() {
        return projectionMatrix;
    }

    public Mat4 getViewMatrix() {
        return viewMatrix;
    }

    public void render(Canvas canvas) {
        var vertices = List.of(
                new Vec3(-0.5f, 0.5f, 0.5f),
                new Vec3(-0.5f, 0.5f, -0.5f),
                new Vec3(0.5f, 0.5f, -0.5f),
                new Vec3(0.5f, 0.5f, 0.5f),
                new Vec3(-0.5f, -0.5f, 0.5f),
                new Vec3(-0.5f, -0.5f, -0.5f),
                new Vec3(0.5f, -0.5f, -0.5f),
                new Vec3(0.5f, -0.5f, 0.5f)
        );

        var indices = List.of(
                List.of(3, 1, 0),
                List.of(2, 1, 3),
                List.of(2, 5, 1),
                List.of(6, 5, 2),
                List.of(6, 4, 5),
                List.of(7, 4, 6),
                List.of(7, 0, 4),
                List.of(3, 0, 7),
                List.of(7, 2, 3),
                List.of(6, 2, 7),
                List.of(0, 5, 4),
                List.of(1, 5, 0)
        );
        float[][] modelMatrix = new float[][]{
                {100, 0, 0, 0},
                {0, 100, 0, 0},
                {0, 0, 100, 0},
                {0, 0, 0, 1}
        };
        triangleMesh = new TriangleMesh(vertices, indices, new ModelMatrix(modelMatrix));

        rerender(canvas);
    }

    public void rerender(@NotNull Canvas canvas) {
        canvas.clearDrawables();

        List<ScreenTriangle> triangles;
        if (usesPerspective) {
            triangles = triangleMesh.renderToScreen(perspectiveProjectionMatrix, viewMatrix, camera.getViewMatrix(), isWireFrame, light, useBackfaceCulling);
        }
        else {
            triangles = triangleMesh.renderToScreen(projectionMatrix, viewMatrix, camera.getViewMatrix(), isWireFrame, light, useBackfaceCulling);
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
            var orig = ModelMatrix.eulerAnglesFromRotationMatrix(rot);
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

    public void resetRotationExponentialMap(Canvas canvas) {

        new Thread(() -> {
            var rot = triangleMesh.getRotationMatrix();
            var orig = ModelMatrix.axisAngleFromRotationMatrix(rot);
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

    public void resetRotationQuaternion(Canvas canvas) {
        new Thread(() -> {
           var rot = triangleMesh.getRotationMatrix();
           var orig = ModelMatrix.quaternionFromRotationMatrix(rot);
           var dest = new Vec4(-1, 0, 0, 0);
           for (float i = 0.0f; i <= 1.0f; i += 0.01f) {
               var current = triangleMesh.quaternionSLERP(orig, dest, i);
               triangleMesh.setRotationQuaternion(current);
               rerender(canvas);
               try {
                   Thread.sleep(10);
               } catch (InterruptedException e) {
                   throw new RuntimeException(e);
               }
           }
        }).start();
    }

}
