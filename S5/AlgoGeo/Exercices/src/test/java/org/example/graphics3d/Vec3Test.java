package org.example.graphics3d;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.assertEquals;

public class Vec3Test {
    private final Vec3 vec3 = new Vec3(1, 2, 3);
    private final Vec3 vec31 = new Vec3(7, 8, 9);

    @Test
    void length() {
        var measuredLength = vec3.length();
        float realLength = (float) Math.sqrt(1 + 4 + 9);
        assertEquals(measuredLength, realLength);
    }

    @Test
    void normalize() {
        var measuredNormal = vec3.normalize();
        float realLength = (float) Math.sqrt(1 + 4 + 9);
        var realNormal = new Vec3((float) (1f / realLength), (float) (2f / realLength), (float) (3f / realLength));
        assertEquals(measuredNormal, realNormal);
    }
//        System.out.println("vec3 negate = " + vec3.negate());
//        System.out.println("vec3 + vec3 = " + vec3.add(vec3));
//        System.out.println("vec3 + (7, 8, 9) = " + vec3.add(7, 8, 9));
//        System.out.println("vec3 * 5 = " + vec3.mul(5));
//        System.out.println("vec3 * vec3 = " + vec3.mul(vec3));
//        System.out.println("vec3 * (7, 8, 9) = " + vec3.mul(7, 8, 9));
//        System.out.println("vec3 . (7, 8, 9) = " + vec3.dot(new Vec3(7, 8, 9)));
//        System.out.println("vec3 × (7, 8, 9) = " + vec3.cross(new Vec3(7, 8, 9)));
//        System.out.println("vec3 → vec4 = " + vec3.homogenous());

    // TODO Put into test
//
//        float[][] matrix = {{2, 9, 6, 7}, {1, 9, 9, 4}, {5, 9, 2, 4}, {5, 6, 6, 1}};
//        float[][] otherMatrix = {{6, 8, 3, 8}, {9, 6, 2, 3}, {3, 1, 4, 8}, {5, 7, 5, 5}};
//        Mat4 mat4 = new Mat4(matrix);
//        Mat4 otherMat4 = new Mat4(otherMatrix);
//        Vec4 vec4 = new Vec4(9, 7, 8, 7);
//        System.out.println(mat4);
//        System.out.println("mat4 * 5 = " + mat4.mul(5));
//        System.out.println(otherMat4);
//        System.out.println("mat4 * otherMat4 = " + mat4.mul(otherMat4));
//        System.out.println(vec4);
//        System.out.println("mat4 * vec4 = " + mat4.mul(vec4));
//        System.out.println("mat4 inv = " + mat4.inverse());
}
