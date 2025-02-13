#pragma once

/* STD */
#include <vector>

/* GLM */
#include <glm/vec2.hpp>

struct BrushStrokePoint
{
    glm::vec2 coords;
};

struct BrushStroke
{
    std::vector<BrushStrokePoint> points;
};