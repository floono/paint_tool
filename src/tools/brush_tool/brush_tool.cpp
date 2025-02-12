/* STDLIB */
#include <memory>
#include <stack>

/* GLM */
#include <glm/vec2.hpp>

/* GLAD */
#include <glad/glad.h>

/* SOURCE*/
#include <tools/brush_tool/brush_tool.h>
#include <commands/command.h>
#include <commands/cmd_brush_stroke.h>

void BrushTool::on_press(glm::vec2 ndc, Layer* current_layer)
{
    if(!current_stroke.points.empty())
    {
        current_stroke.points.clear();
    }

    BrushStrokePoint point = {ndc};
    current_stroke.points.push_back(point);
}

void BrushTool::on_hold(glm::vec2 ndc, Layer* current_layer)
{
    BrushStrokePoint point = {ndc};
    current_stroke.points.push_back(point);
}

void BrushTool::on_release(glm::vec2 ndc, Layer* current_layer)
{
    std::unique_ptr<CMD_Brush_Stroke> cmd = std::make_unique<CMD_Brush_Stroke>(current_stroke, current_layer);
    cmd_history.command_stack.push(std::move(cmd));
}