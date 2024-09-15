package org.example.graphics3d;

import org.jetbrains.annotations.NotNull;

import java.util.Arrays;
import java.util.StringJoiner;

public class Mat4 {
    protected float[][] matrix;

    public Mat4() {
        matrix = new float[4][4];
    }

    public Mat4(float @NotNull [] @NotNull [] matrix) {
        this.matrix = new float[4][4];
        for (int i = 0; i < matrix.length; i++) {
            System.arraycopy(matrix[i], 0, this.matrix[i], 0, matrix[i].length);
        }
    }

    public Mat4(@NotNull Mat4 matrix) {
        this.matrix = new float[4][4];
        for (int i = 0; i < matrix.matrix.length; i++) {
            System.arraycopy(matrix.matrix[i], 0, this.matrix[i], 0, matrix.matrix[i].length);
        }
    }

    public Mat4(float a00, float a01, float a02, float a03, float a10, float a11, float a12, float a13, float a20, float a21, float a22, float a23, float a30, float a31, float a32, float a33) {
        matrix = new float[][]{
                {a00, a01, a02, a03},
                {a10, a11, a12, a13},
                {a20, a21, a22, a23},
                {a30, a31, a32, a33}
        };
    }

    public float[][] getMatrix() {
        return matrix;
    }

    public Mat4 mul(float k) {
        Mat4 result = new Mat4(matrix);
        for (float[] row : result.matrix) {
            for (int i = 0; i < 4; i++) {
                row[i] *= k;
            }
        }
        return result;
    }

    public Mat4 mul(@NotNull Mat4 matrix) {
        float[][] newMatrix = new float[4][4];
        for (int i = 0; i < this.matrix.length; i++) {
            for (int j = 0; j < this.matrix.length; j++) {
                float sum = 0;
                for (int k = 0; k < this.matrix.length; k++) {
                    sum += this.matrix[i][k] * matrix.matrix[k][j];
                }
                newMatrix[i][j] = sum;
            }
        }
        return new Mat4(newMatrix);
    }

    public Vec4 mul(@NotNull Vec4 vec4) {
        Vec4 result = new Vec4(0, 0, 0, 0);
        result.setX(matrix[0][0] * vec4.getX() + matrix[0][1] * vec4.getY() + matrix[0][2] * vec4.getZ() + matrix[0][3] * vec4.getW());
        result.setY(matrix[1][0] * vec4.getX() + matrix[1][1] * vec4.getY() + matrix[1][2] * vec4.getZ() + matrix[1][3] * vec4.getW());
        result.setZ(matrix[2][0] * vec4.getX() + matrix[2][1] * vec4.getY() + matrix[2][2] * vec4.getZ() + matrix[2][3] * vec4.getW());
        result.setW(matrix[3][0] * vec4.getX() + matrix[3][1] * vec4.getY() + matrix[3][2] * vec4.getZ() + matrix[3][3] * vec4.getW());
        return result;
    }

    public float determinant() {
        return matrix[0][0] * (matrix[1][1] * matrix[2][2] * matrix[3][3] + matrix[1][2] * matrix[2][3] * matrix[3][1] + matrix[1][3] * matrix[2][1] * matrix[3][2]
                - matrix[1][3] * matrix[2][2] * matrix[3][1] - matrix[1][2] * matrix[2][1] * matrix[3][3] - matrix[1][1] * matrix[2][3] * matrix[3][2])
                - matrix[1][0] * (matrix[0][1] * matrix[2][2] * matrix[3][3] + matrix[0][2] * matrix[2][3] * matrix[3][1] + matrix[0][3] * matrix[2][1] * matrix[3][2]
                - matrix[0][3] * matrix[2][2] * matrix[3][1] - matrix[0][2] * matrix[2][1] * matrix[3][3] - matrix[0][1] * matrix[2][3] * matrix[3][2])
                + matrix[2][0] * (matrix[0][1] * matrix[1][2] * matrix[3][3] + matrix[0][2] * matrix[1][3] * matrix[3][1] + matrix[0][3] * matrix[1][1] * matrix[3][2]
                - matrix[0][3] * matrix[1][2] * matrix[3][1] - matrix[0][2] * matrix[1][1] * matrix[3][3] - matrix[0][1] * matrix[1][3] * matrix[3][2])
                - matrix[3][0] * (matrix[0][1] * matrix[1][2] * matrix[2][3] + matrix[0][2] * matrix[1][3] * matrix[2][1] + matrix[0][3] * matrix[1][1] * matrix[2][2]
                - matrix[0][3] * matrix[1][2] * matrix[2][1] - matrix[0][2] * matrix[1][1] * matrix[2][3] - matrix[0][1] * matrix[1][3] * matrix[2][2]);
    }

    public Mat4 adjugate() {
        float a00 = (matrix[1][1] * matrix[2][2] * matrix[3][3] + matrix[1][2] * matrix[2][3] * matrix[3][1] + matrix[1][3] * matrix[2][1] * matrix[3][2]
                - matrix[1][3] * matrix[2][2] * matrix[3][1] - matrix[1][2] * matrix[2][1] * matrix[3][3] - matrix[1][1] * matrix[2][3] * matrix[3][2]);
        float a01 = -(matrix[0][1] * matrix[2][2] * matrix[3][3] + matrix[0][2] * matrix[2][3] * matrix[3][1] + matrix[0][3] * matrix[2][1] * matrix[3][2]
                - matrix[0][3] * matrix[2][2] * matrix[3][1] - matrix[0][2] * matrix[2][1] * matrix[3][3] - matrix[0][1] * matrix[2][3] * matrix[3][2]);
        float a02 = (matrix[0][1] * matrix[1][2] * matrix[3][3] + matrix[0][2] * matrix[1][3] * matrix[3][1] + matrix[0][3] * matrix[1][1] * matrix[3][2]
                - matrix[0][3] * matrix[1][2] * matrix[3][1] - matrix[0][2] * matrix[1][1] * matrix[3][3] - matrix[0][1] * matrix[1][3] * matrix[3][2]);
        float a03 = -(matrix[0][1] * matrix[1][2] * matrix[2][3] + matrix[0][2] * matrix[1][3] * matrix[2][1] + matrix[0][3] * matrix[1][1] * matrix[2][2]
                - matrix[0][3] * matrix[1][2] * matrix[2][1] - matrix[0][2] * matrix[1][1] * matrix[2][3] - matrix[0][1] * matrix[1][3] * matrix[2][2]);
        float a10 = -(matrix[1][0] * matrix[2][2] * matrix[3][3] + matrix[1][2] * matrix[2][3] * matrix[3][0] + matrix[1][3] * matrix[2][0] * matrix[3][2]
                - matrix[1][3] * matrix[2][2] * matrix[3][0] - matrix[1][2] * matrix[2][0] * matrix[3][3] - matrix[1][0] * matrix[2][3] * matrix[3][2]);
        float a11 = (matrix[0][0] * matrix[2][2] * matrix[3][3] + matrix[0][2] * matrix[2][3] * matrix[3][0] + matrix[0][3] * matrix[2][0] * matrix[3][2]
                - matrix[0][3] * matrix[2][2] * matrix[3][0] - matrix[0][2] * matrix[2][0] * matrix[3][3] - matrix[0][0] * matrix[2][3] * matrix[3][2]);
        float a12 = -(matrix[0][0] * matrix[1][2] * matrix[3][3] + matrix[0][2] * matrix[1][3] * matrix[3][0] + matrix[0][3] * matrix[1][0] * matrix[3][2]
                - matrix[0][3] * matrix[1][2] * matrix[3][0] - matrix[0][2] * matrix[1][0] * matrix[3][3] - matrix[0][0] * matrix[1][3] * matrix[3][2]);
        float a13 = (matrix[0][0] * matrix[1][2] * matrix[2][3] + matrix[0][2] * matrix[1][3] * matrix[2][0] + matrix[0][3] * matrix[1][0] * matrix[2][2]
                - matrix[0][3] * matrix[1][2] * matrix[2][0] - matrix[0][2] * matrix[1][0] * matrix[2][3] - matrix[0][0] * matrix[1][3] * matrix[2][2]);
        float a20 = (matrix[1][0] * matrix[2][1] * matrix[3][3] + matrix[1][1] * matrix[2][3] * matrix[3][0] + matrix[1][3] * matrix[2][0] * matrix[3][1]
                - matrix[1][3] * matrix[2][1] * matrix[3][0] - matrix[1][1] * matrix[2][0] * matrix[3][3] - matrix[1][0] * matrix[2][3] * matrix[3][1]);
        float a21 = -(matrix[0][0] * matrix[2][1] * matrix[3][3] + matrix[0][1] * matrix[2][3] * matrix[3][0] + matrix[0][3] * matrix[2][0] * matrix[3][1]
                - matrix[0][3] * matrix[2][1] * matrix[3][0] - matrix[0][1] * matrix[2][0] * matrix[3][3] - matrix[0][0] * matrix[2][3] * matrix[3][1]);
        float a22 = (matrix[0][0] * matrix[1][1] * matrix[3][3] + matrix[0][1] * matrix[1][3] * matrix[3][0] + matrix[0][3] * matrix[1][0] * matrix[3][1]
                - matrix[0][3] * matrix[1][1] * matrix[3][0] - matrix[0][1] * matrix[1][0] * matrix[3][3] - matrix[0][0] * matrix[1][3] * matrix[3][1]);
        float a23 = -(matrix[0][0] * matrix[1][1] * matrix[2][3] + matrix[0][1] * matrix[1][3] * matrix[2][0] + matrix[0][3] * matrix[1][0] * matrix[2][1]
                - matrix[0][3] * matrix[1][1] * matrix[2][0] - matrix[0][1] * matrix[1][0] * matrix[2][3] - matrix[0][0] * matrix[1][3] * matrix[2][1]);
        float a30 = -(matrix[1][0] * matrix[2][1] * matrix[3][2] + matrix[1][1] * matrix[2][2] * matrix[3][0] + matrix[1][2] * matrix[2][0] * matrix[3][1]
                - matrix[1][2] * matrix[2][1] * matrix[3][0] - matrix[1][1] * matrix[2][0] * matrix[3][2] - matrix[1][0] * matrix[2][2] * matrix[3][1]);
        float a31 = (matrix[0][0] * matrix[2][1] * matrix[3][2] + matrix[0][1] * matrix[2][2] * matrix[3][0] + matrix[0][2] * matrix[2][0] * matrix[3][1]
                - matrix[0][2] * matrix[2][1] * matrix[3][0] - matrix[0][1] * matrix[2][0] * matrix[3][2] - matrix[0][0] * matrix[2][2] * matrix[3][1]);
        float a32 = -(matrix[0][0] * matrix[1][1] * matrix[3][2] + matrix[0][1] * matrix[1][2] * matrix[3][0] + matrix[0][2] * matrix[1][0] * matrix[3][1]
                - matrix[0][2] * matrix[1][1] * matrix[3][0] - matrix[0][1] * matrix[1][0] * matrix[3][2] - matrix[0][0] * matrix[1][2] * matrix[3][1]);
        float a33 = (matrix[0][0] * matrix[1][1] * matrix[2][2] + matrix[0][1] * matrix[1][2] * matrix[2][0] + matrix[0][2] * matrix[1][0] * matrix[2][1]
                - matrix[0][2] * matrix[1][1] * matrix[2][0] - matrix[0][1] * matrix[1][0] * matrix[2][2] - matrix[0][0] * matrix[1][2] * matrix[2][1]);

        float[][] newMatrix = {{a00, a01, a02, a03}
                , {a10, a11, a12, a13}
                , {a20, a21, a22, a23}
                , {a30, a31, a32, a33}};
        return new Mat4(newMatrix);
    }

    public Mat4 inverse() {
        Mat4 adjugate = adjugate();
        float det = determinant();
        return adjugate.mul(1 / det);
    }

    public float trace() {
        float trace = 0;
        for (int i = 0; i < matrix.length; i++) {
            trace += matrix[i][i];
        }
        return trace;
    }

    public float trace(int size) {
        if (size > matrix.length) {
            return trace();
        }
        float trace = 0;
        for (int i = 0; i < size; i++) {
            trace += matrix[i][i];
        }
        return trace;
    }

    @Override
    public String toString() {
        StringJoiner sj = new StringJoiner(", ");
        for (float[] row : matrix) {
            StringJoiner joiner = new StringJoiner(", ");
            for (float v : row) {
                joiner.add(String.valueOf(v));
            }
            sj.add("{" + joiner + "}");
        }
        return "Mat4{" + sj + "}";
    }

    public void print() {
        System.out.println(toString());
    }
}
