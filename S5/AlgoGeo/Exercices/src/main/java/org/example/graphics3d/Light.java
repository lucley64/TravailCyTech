package org.example.graphics3d;

public class Light extends Model {
    public Light(Vec3 position) {

        super(new ModelMatrix());

        translate(position);
    }

    public Light(float x, float y, float z) {
        super(new ModelMatrix());
        translate(x, y, z);
    }
}
