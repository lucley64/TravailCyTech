//
// Created by cytech on 24/09/24.
//

#ifndef GL2_EBO_H
#define GL2_EBO_H


#include <GL/gl.h>

class ebo {
public:
    GLuint ID;

    template<unsigned int size>
    ebo(const GLuint (&indices)[size]){
        glGenBuffers(1, &ID);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, indices, GL_STATIC_DRAW);
    }

    void Bind();

    void Unbind();

    void Delete();
};


#endif //GL2_EBO_H
