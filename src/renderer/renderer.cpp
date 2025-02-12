#include <glad/glad.h>

/* SOURCE */
#include <renderer/renderer.h>

void Renderer::init()
{
    /* VAO creation and binding */
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    /* VBO creation and binding */
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    /* Linking vertex buffer to drawn points data */
    glBufferData(GL_ARRAY_BUFFER, 100000, NULL, GL_DYNAMIC_DRAW);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
}

void Renderer::render()
{
    
}