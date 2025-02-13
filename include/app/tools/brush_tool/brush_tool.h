#pragma once

/* STDLIB */
#include <vector>
#include <memory>

/* GLM  */
#include <glm/vec2.hpp>

/* SOURCE */
#include "app/tools/tool.h"
#include "app/tools/brush_tool/brush_stroke.h"

class BrushTool : public Tool
{
    private:
        BrushStroke current_stroke;

    public:
        void on_press(glm::vec2 ndc) override;
        void on_hold(glm::vec2 ndc) override;
        void on_release(glm::vec2 ndc) override;
};