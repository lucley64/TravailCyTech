package org.example.graphics3d;

import org.jetbrains.annotations.NotNull;

import java.awt.*;
import java.util.ArrayList;
import java.util.List;

public class TriangleMesh extends Model {
    private List<Vec3> vertices;
    private List<List<Integer>> faces;

    public TriangleMesh(List<Vec3> vertices, List<List<Integer>> faces, ModelMatrix modelMatrix) {
        super(modelMatrix);
        this.vertices = vertices;
        this.faces = faces;
    }

    public List<Vec3> getVertices() {
        return vertices;
    }

    public List<List<Integer>> getFaces() {
        return faces;
    }

    public List<ScreenTriangle> renderToScreen(Mat4 projectionMatrix, Mat4 viewPortMatrix, Mat4 viewMatrix, boolean isWireframe, Light light, boolean useBackfaceCulling) {
        List<ScreenTriangle> screenTriangles = new ArrayList<>();
        for (List<Integer> face : faces) {
            var v0World = modelMatrix.mul(vertices.get(face.get(0)).homogenous());
            var v1World = modelMatrix.mul(vertices.get(face.get(1)).homogenous());
            var v2World = modelMatrix.mul(vertices.get(face.get(2)).homogenous());
            var a = v1World.cartesian().sub(v0World.cartesian());
            var b = v2World.cartesian().sub(v0World.cartesian());
            var n = a.cross(b).mul(1/a.cross(b).length());
            var center = v0World.cartesian().add(v1World.cartesian().add(v2World.cartesian())).mul(1f / 3f);
            var lightPos = new Vec3(light.modelMatrix.matrix[0][3], light.modelMatrix.matrix[1][3], light.modelMatrix.matrix[2][3]);
            var lightDir = center.sub(lightPos);
            float colorFactor = Math.max(lightDir.mul(1/-lightDir.length()).dot(n.mul(1/n.length())), 0);
            var color = new Color(colorFactor, colorFactor, colorFactor);
            var v0Cam = viewMatrix.mul(v0World);
            var v1Cam = viewMatrix.mul(v1World);
            var v2Cam = viewMatrix.mul(v2World);
            a = v1Cam.cartesian().sub(v0Cam.cartesian());
            b = v2Cam.cartesian().sub(v0Cam.cartesian());
            n = a.cross(b).mul(1/a.cross(b).length());
            if (!useBackfaceCulling || n.getZ() >= 0) {
                var v0 = viewPortMatrix.mul(projectionMatrix.mul(v0Cam).cartesian().homogenous());
                var v1 = viewPortMatrix.mul(projectionMatrix.mul(v1Cam).cartesian().homogenous());
                var v2 = viewPortMatrix.mul(projectionMatrix.mul(v2Cam).cartesian().homogenous());

                screenTriangles.add(new ScreenTriangle(v0.cartesian(), v1.cartesian(), v2.cartesian(), !isWireframe, color));
            }
        }
        return screenTriangles;
    }

    public Vec3 eulerAnglesLERP(Vec3 v0, Vec3 v1, float t) {
        return modelMatrix.eulerAnglesLERP(v0, v1, t);
    }

    public Vec4 anglesAxisLERP(Vec4 v0, Vec4 v1, float t) {
        return modelMatrix.anglesAxisLERP(v0, v1, t);
    }
}
