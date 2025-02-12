#pragma once

/* GLM */
#include <glm/vec2.hpp>

/* SOURCE */
#include <layers/layer.h>

class Tool
{
    public:
        virtual void on_press(glm::vec2 ndc, Layer* current_layer) = 0;
        virtual void on_hold(glm::vec2 ndc, Layer* current_layer) = 0;
        virtual void on_release(glm::vec2 ndc, Layer* current_layer) = 0;
        virtual ~Tool() = default;
};