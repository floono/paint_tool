/* Source Includes */
#include <tools/brush_tool/brush_tool.h>

void BrushTool::on_press()
{
    if(!current_stroke.points.empty())
    {
        current_stroke.points.clear();
    }

    is_drawing = true;

}

void BrushTool::on_hold()
{

}

void BrushTool::on_release()
{

}