//
// Created by cytech on 24/09/24.
//

#include <GL/glew.h>
#include "vbo.h"

void vbo::Bind() {
    glBindBuffer(GL_ARRAY_BUFFER, ID);
}

void vbo::Unbind() {
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void vbo::Delete() {
    glDeleteBuffers(1, &ID);
}