/* GLAD */
#include <glad/glad.h>

/* GLM */
#include <glm/vec2.hpp>

/* SOURCE */
#include "app/project/layers/layer.h"
#include "app/tools/brush_tool/brush_tool.h"

Layer::Layer()
{
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    glBufferData(GL_ARRAY_BUFFER, 100000 * sizeof(glm::vec2), NULL, GL_DYNAMIC_DRAW); // TEMPORARY HARDCODED BUFFER SIZE
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(glm::vec2), (void*)0);
    glEnableVertexAttribArray(0);

    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, 1280, 720, 0, GL_RGBA, GL_UNSIGNED_BYTE, nullptr);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glGenFramebuffers(1, &FBO);
    glBindFramebuffer(GL_FRAMEBUFFER, FBO);
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, texture, 0);
    
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

Layer::~Layer()
{
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteFramebuffers(1, &FBO);
    glDeleteTextures(1, &texture);
}

unsigned int Layer::get_texture()
{
    return texture;
}

void Layer::add_stroke(BrushStroke stroke)
{
    size_t brush_stroke_size = stroke.points.size() * sizeof(glm::vec2);

    brush_strokes.push_back(stroke);

    glBindFramebuffer(GL_FRAMEBUFFER, FBO);
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    
    glPointSize(5.0f);
    glBufferSubData(GL_ARRAY_BUFFER, brush_strokes_size, brush_stroke_size, stroke.points.data());
    glDrawArrays(GL_POINTS, brush_strokes_size / sizeof(glm::vec2), stroke.points.size());

    glBindFramebuffer(GL_FRAMEBUFFER, 0);

    brush_strokes_size += brush_stroke_size;
}

void Layer::remove_stroke()
{   
    size_t brush_stroke_size = brush_strokes.back().points.size() * sizeof(glm::vec2);
    brush_strokes_size -= brush_stroke_size;
    brush_strokes.pop_back();
}