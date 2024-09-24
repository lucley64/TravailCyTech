//
// Created by cytech on 24/09/24.
//

#include <GL/glew.h>
#include "vao.h"

vao::vao() {
    glGenVertexArrays(1, &ID);
}

void vao::LinkAttrib(vbo &VBO, GLuint layout, GLuint numComponent, GLenum type, GLsizeiptr stride, void *offset) {
    VBO.Bind();
    glVertexAttribPointer(layout, numComponent, type, GL_FALSE, stride, offset);
    glEnableVertexAttribArray(layout);
    VBO.Unbind();
}

void vao::Bind() {
    glBindVertexArray(ID);
}

void vao::Unbind() {
    glBindVertexArray(0);
}

void vao::Delete() {
    glDeleteVertexArrays(1, &ID);
}