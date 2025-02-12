/* SOURCE */
#include <layers/layer.h>
#include <tools/brush_tool/brush_tool.h>

void Layer::add_stroke(BrushStroke stroke)
{
    brush_strokes.push_back(stroke);
}

void Layer::remove_stroke()
{
    brush_strokes.pop_back();
}