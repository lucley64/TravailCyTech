//
// Created by cytech on 24/09/24.
//

#ifndef GL2_VBO_H
#define GL2_VBO_H


#include <GL/gl.h>

class vbo {
public:
    GLuint ID;

    template<unsigned int size>
    vbo(const GLfloat (&vertices)[size]){
        glGenBuffers(1, &ID);
        glBindBuffer(GL_ARRAY_BUFFER, ID);
        glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
    }

    void Bind();

    void Unbind();

    void Delete();
};


#endif //GL2_VBO_H
