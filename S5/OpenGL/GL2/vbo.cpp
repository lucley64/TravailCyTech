//
// Created by cytech on 24/09/24.
//

#include <GL/glew.h>
#include "vbo.h"

void gl2::vbo::bind() {
    glBindBuffer(GL_ARRAY_BUFFER, ID);
}

void gl2::vbo::unbind() {
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

gl2::vbo::~vbo() {
    glDeleteBuffers(1, &ID);
}