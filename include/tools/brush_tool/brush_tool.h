#pragma once

/* Standards Library Includes */
#include <vector>

/* Source Includes */
#include <tools/tool.h>

struct BrushStrokePoint
{
    float x, y;
};

struct BrushStroke
{
    std::vector<BrushStrokePoint> points;
};

class BrushTool : public Tool
{
    private:
        BrushStroke current_stroke;
        bool is_drawing = false;

    public:
        void on_press() override;
        void on_hold() override;
        void on_release() override;
};