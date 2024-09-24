//
// Created by cytech on 24/09/24.
//

#ifndef GL2_VBO_H
#define GL2_VBO_H


#include <GL/gl.h>
#include <array>
#include <vector>
#include "glm/vec4.hpp"

namespace gl2 {
    class vbo {
    public:
        GLuint ID;

        template<unsigned int size>
        vbo(const GLfloat (&vertices)[size]) {
            glGenBuffers(1, &ID);
            glBindBuffer(GL_ARRAY_BUFFER, ID);
            glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
        }

        vbo(const std::vector<glm::vec4> positions, const std::vector<glm::vec4> colors) {
            glGenBuffers(1, &ID);
            glBindBuffer(GL_ARRAY_BUFFER, ID);
            int sp = positions.size() * sizeof(glm::vec4);
            int sc = colors.size() * sizeof(glm::vec4);
            glBufferData(GL_ARRAY_BUFFER, sp + sc, nullptr, GL_STATIC_DRAW);
            glBufferSubData(GL_ARRAY_BUFFER, 0, sp, positions.data());
            glBufferSubData(GL_ARRAY_BUFFER, sp, sc, colors.data());
        }

        void bind();

        void unbind();

        ~vbo();
    };
}


#endif //GL2_VBO_H
