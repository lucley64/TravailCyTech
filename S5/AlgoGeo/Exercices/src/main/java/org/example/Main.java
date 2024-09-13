package org.example;

import org.example.canvas.Canvas;
import org.example.canvas.GuiHelper;
import org.example.graphics3d.*;

import java.awt.*;

public class Main {
    private static final float height = 600;
    private static final float width = 800;
    private static final float fov = 1f;
    private static final float near = 0.1f;
    private static final float far = 100f;

    public static void main(String[] args) {
//        Canvas canvas = new Canvas();
//        canvas.setPreferredSize(new Dimension(800, 600));
//        canvas.setBackground(Color.WHITE);
//
//        Polygon polygon = new Polygon();
//
//        canvas.addDrawable(polygon);
//        new MouseDraw(canvas, polygon);
//        GuiHelper.showOnFrame(canvas, "test");


        Canvas canvas = new Canvas();
        canvas.setPreferredSize(new Dimension(800, 600));
        canvas.setBackground(Color.WHITE);

        var d = 1 / (float) Math.tan(fov / 2);

        float[][] perspectiveProjectionMatrix = {
                {d / -(width / height), 0, 0, 0},
                {0, d, 0, 0},
                {0, 0, (near + far) / (near - far), (2 * near * far) / (near - far)},
                {0, 0, -1, 0}
        };

        float[][] orthographicProjectionMatrix = new float[][]{
                {2f / width, 0, 0, 0},
                {0, 2f / height, 0, 0},
                {0, 0, -2f / (far - near), -((far + near) / (far - near))},
                {0, 0, 0, 1}
        };

        float[][] viewPortMatrix = new float[][]{
                {800f / 2f, 0, 0, 800f / 2f},
                {0, -600f / 2f, 0, 600f - 600f / 2f},
                {0, 0, 1f / 2f, 1f / 2f},
                {0, 0, 0, 1}
        };

        Scene scene = new Scene(new Mat4(orthographicProjectionMatrix), new Mat4(perspectiveProjectionMatrix), new Mat4(viewPortMatrix), new Camera(new Vec3(0, 0, -1000), new Vec3(0, 0, 0)), true);
        scene.render(canvas);

        new KeyboardMovement(canvas, scene);

        GuiHelper.showOnFrame(canvas, "C'est en 3D");
    }
}