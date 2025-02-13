/* STDLIB */
#include <memory>
#include <stack>

/* GLM */
#include <glm/vec2.hpp>

/* GLAD */
#include <glad/glad.h>

/* SOURCE*/
#include "app/tools/brush_tool/brush_tool.h"

void BrushTool::on_press(glm::vec2 ndc)
{
    if(!current_stroke.points.empty())
    {
        current_stroke.points.clear();
    }

    BrushStrokePoint point = {ndc};
    current_stroke.points.push_back(point);
}

void BrushTool::on_hold(glm::vec2 ndc)
{
    BrushStrokePoint point = {ndc};
    current_stroke.points.push_back(point);
}

void BrushTool::on_release(glm::vec2 ndc)
{

}