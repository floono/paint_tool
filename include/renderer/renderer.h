#pragma once

/* STDLIB */
#include <vector>
#include <memory>

/* SOURCE */
class Layer;

class Renderer
{
    private:
        unsigned int VAO, VBO;
        std::vector<std::shared_ptr<Layer>> layers;
    public:
        void init();
        void render();
};