/* GLAD */
#include <glad/glad.h>

/* GLM */
#include <glm/vec2.hpp>

/* SOURCE */
#include <layers/layer.h>
#include <tools/brush_tool/brush_tool.h>

Layer::Layer()
{
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    glBufferData(GL_ARRAY_BUFFER, 100000 * sizeof(glm::vec2), NULL, GL_DYNAMIC_DRAW);
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
    glDeleteTextures(1, &texture);
}

void Layer::add_stroke(BrushStroke stroke)
{
    brush_strokes.push_back(stroke);

    size_t bytes = 0;

    glBindFramebuffer(GL_FRAMEBUFFER, FBO);
    for(BrushStroke s : brush_strokes)
    {
        glPointSize(5.0f);
    }
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

void Layer::remove_stroke()
{
    brush_strokes.pop_back();
}