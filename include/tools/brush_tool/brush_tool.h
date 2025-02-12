#pragma once

/* STDLIB */
#include <vector>
#include <memory>

/* GLM  */
#include <glm/vec2.hpp>

/* SOURCE */
#include <tools/tool.h>

class Layer;

struct BrushStrokePoint
{
    glm::vec2 coords;
};

struct BrushStroke
{
    std::vector<BrushStrokePoint> points;
};

class BrushTool : public Tool
{
    private:
        BrushStroke current_stroke;

    public:
        void on_press(glm::vec2 ndc, Layer* current_layer) override;
        void on_hold(glm::vec2 ndc, Layer* current_layer) override;
        void on_release(glm::vec2 ndc, Layer* current_layer) override;
};