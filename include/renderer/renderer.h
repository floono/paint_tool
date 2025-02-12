#pragma once

/* STDLIB */
#include <vector>
#include <memory>

/* SOURCE */
class Layer;

class Renderer
{
    private:
        unsigned int VAO, VBO, FBO;
        std::vector<std::shared_ptr<Layer>> layers;

        void render_layers_to_textures();
    public:
        void init();
        void render();
};