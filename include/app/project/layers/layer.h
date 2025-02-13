#pragma once

/* STD */
#include <vector>

/* SRC */
#include "app/tools/brush_tool/brush_tool.h"

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
        unsigned int get_texture();
        void add_stroke(BrushStroke stroke);
        void remove_stroke();
};