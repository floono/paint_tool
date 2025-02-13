/* GLAD */
#include <glad/glad.h>

/* SOURCE */
#include "app/renderer/renderer.h"
#include "app/shaders/shader.h"
#include "app/project/layers/layer.h"

Renderer::Renderer()
{
    float quad[] = {
        // Positions      // Texture Coords
        -1.0f,  1.0f,     0.0f, 1.0f,
        -1.0f, -1.0f,     0.0f, 0.0f,
         1.0f, -1.0f,     1.0f, 0.0f,
         1.0f,  1.0f,     1.0f, 1.0f
    };

    /* VAO creation and binding */
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    /* VBO creation and binding */
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    /* Linking vertex buffer to quad that textures are painted onto */
    glBufferData(GL_ARRAY_BUFFER, sizeof(quad), quad, GL_STATIC_DRAW);

    /* Quad attribute pointers */
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)(2 * sizeof(float)));
    glEnableVertexAttribArray(1);

    /* Offscreen FBO creation */
    glGenFramebuffers(1, &FBO);
    glBindFramebuffer(GL_FRAMEBUFFER, FBO);

    glBindVertexArray(0);
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

Renderer::~Renderer()
{
    glDeleteBuffers(1, &VBO);
    glDeleteVertexArrays(1, &VAO);
    glDeleteFramebuffers(1, &FBO);
}

void Renderer::render()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    
    shader.use();

    glBindVertexArray(VAO);

    /*for(Layer layer : layers)
    {
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, layer.get_texture());

        glUniform1i(glGetUniformLocation(shader.id, "u_layer_texture"), 0);

        glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
    }*/

    glBindTexture(GL_TEXTURE_2D, 0);
    glBindVertexArray(0);

    glDisable(GL_BLEND);
}