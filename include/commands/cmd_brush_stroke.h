#pragma once

/* SOURCE */
#include <commands/command.h>
#include <tools/brush_tool/brush_tool.h>
#include <layers/layer.h>

class CMD_Brush_Stroke : public Command
{
    private:
        BrushStroke brush_stroke;
        Layer* layer;

    public:
        CMD_Brush_Stroke(BrushStroke stroke, Layer* layer);
        void execute() override;
        void undo() override;
};