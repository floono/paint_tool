#include <glad/glad.h>

/* SOURCE */
#include <renderer/renderer.h>

void Renderer::init()
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

}

void Renderer::render()
{

}