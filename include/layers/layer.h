#pragma once

/* STDLIB */
#include <vector>

struct BrushStroke; // forward declaration

class Layer
{
    private:
        std::vector<BrushStroke> brush_strokes;
    public:
        void add_stroke(BrushStroke stroke);
        void remove_stroke();
};