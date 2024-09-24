//
// Created by cytech on 24/09/24.
//

#include <GL/glew.h>
#include "vao.h"
#include "vbo.h"

gl2::vao::vao() {
    glGenVertexArrays(1, &ID);
}

void gl2::vao::linkAttrib(vbo &VBO, GLuint layout, GLuint numComponent, GLenum type, GLsizeiptr stride, void *offset) {
    VBO.bind();
    glEnableVertexAttribArray(layout);
    glVertexAttribPointer(layout, numComponent, type, GL_FALSE, stride, offset);
}

void gl2::vao::bind() {
    glBindVertexArray(ID);
}

void gl2::vao::unbind() {
    glBindVertexArray(0);
}

gl2::vao::~vao() {
    glDeleteVertexArrays(1, &ID);
}