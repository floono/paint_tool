#pragma once

/* STDLIB */
#include <vector>

struct BrushStroke; // forward declaration

class Layer
{
    private:
        unsigned int VBO, VAO, FBO;
        unsigned int texture;
        std::vector<BrushStroke> brush_strokes;
        size_t brush_strokes_size = 0;
    public:
        Layer();
        ~Layer();
        void add_stroke(BrushStroke stroke);
        void remove_stroke();
        void render();
};