//
// Created by cytech on 24/09/24.
//

#include <GL/glew.h>
#include "ebo.h"

void ebo::Bind() {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID);
}

void ebo::Unbind() {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void ebo::Delete() {
    glDeleteBuffers(1, &ID);
}