//
// Created by cytech on 24/09/24.
//

#ifndef GL2_VAO_H
#define GL2_VAO_H


#include <GL/gl.h>
#include "vbo.h"

class vao {
public:
    GLuint ID;

    vao();

    void LinkAttrib(vbo &VBO, GLuint layout, GLuint numComponent, GLenum type, GLsizeiptr stride, void *offset);

    void Bind();

    void Unbind();

    void Delete();
};


#endif //GL2_VAO_H
