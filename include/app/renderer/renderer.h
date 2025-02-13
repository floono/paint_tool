#pragma once

/* STD */
#include <vector>
#include <memory>

/* SRC */
#include "app/shaders/shader.h"

class Renderer
{
    private:
        unsigned int VAO, VBO, FBO;
        ShaderProgram shader = {"shaders/view_quad.vert", "shaders/view_quad.frag"};

    public:
        Renderer();
        ~Renderer();
        void render();
};