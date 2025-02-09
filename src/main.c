/* Enable SDL3 callbacks instead of using main() */
#define SDL_MAIN_USE_CALLBACKS 1

/* STD Headers */
#include <stdio.h>
#include <math.h>

/* SDL3 Headers */
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

/* GLAD Headers */
#include <glad/glad.h>

/* STB Headers */
#include <stb_ds.h>

/* SRC Headers */
#include <point.h>
#include <drawing.h>
#include <shader_tools.h>

#define MAX_POINTS 1000000

static SDL_Window* window = NULL;
static SDL_GLContext gl_context = NULL;

int window_width = 1280;
int window_height = 720;

unsigned int VAO, VBO;
ShaderProgram shader_program;

SDL_AppResult SDL_AppInit(void** appstate, int argc, char* argv[])
{
    /* Initializing SDL and relevant SDL subsystems */
    if(!SDL_Init(SDL_INIT_VIDEO)) 
    {
        return SDL_APP_FAILURE;
    }

    /* Configuring OpenGL context */
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

    /* Creating a window with SDL */
    window = SDL_CreateWindow("paint tool", window_width, window_height, SDL_WINDOW_OPENGL);
    if(!window)
    {
        SDL_Log("Failed to create window: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }
    
    /* Creating an OpenGL context and storing it */
    gl_context = SDL_GL_CreateContext(window);
    if(!gl_context)
    {
        SDL_Log("Failed to create OpenGL context: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }

    /* Initializing GLAD for OpenGL function pointers */
    if(!gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress)) 
    {
         SDL_Log("Failed to initialize glad.");
         return SDL_APP_FAILURE;
    }

    shader_program = setupShaders("shaders/basic.vert", "shaders/basic.frag");

    /* VAO creation and binding */
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    /* VBO creation and binding */
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    /* Linking vertex buffer to drawn points data */
    glBufferData(GL_ARRAY_BUFFER, MAX_POINTS * sizeof(Point), NULL, GL_DYNAMIC_DRAW);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppEvent(void* appstate, SDL_Event *event)
{
    if(event->type == SDL_EVENT_QUIT) // Allowing safe exit
    {
        return SDL_APP_SUCCESS;
    }
    if(event->type == SDL_EVENT_WINDOW_RESIZED) // Ensuring OpenGL context resizes with OS window
    {
        window_width = event->window.data1;
        window_height = event->window.data2;
        glViewport(0, 0, window_width, window_height);
    }

    if(event->type == SDL_EVENT_MOUSE_BUTTON_DOWN && event->button.button == SDL_BUTTON_LEFT)
    {
        float ndc_x = (event->button.x / (float)window_width) * 2.0f - 1.0f;
        float ndc_y = 1.0f - (event->button.y / (float)window_height) * 2.0f;
        Point p = {ndc_x, ndc_y};
        start_stroke(p);
    }
    else if(event->type == SDL_EVENT_MOUSE_BUTTON_UP && event->button.button == SDL_BUTTON_LEFT)
    {
        stop_stroke();
    }

    if(event->type == SDL_EVENT_MOUSE_MOTION && drawing)
    {
        float ndc_x = (event->motion.x / (float)window_width) * 2.0f - 1.0f;
        float ndc_y = 1.0f - (event->motion.y / (float)window_height) * 2.0f;
        Point p = { ndc_x, ndc_y };
        add_to_stroke(p);
    }

    return SDL_APP_CONTINUE;
}

/* Runs every frame */
SDL_AppResult SDL_AppIterate(void* appstate)
{
    glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glPointSize(5.0f);
    glUseProgram(shader_program.id);

    /* Updating buffer with new points */
    glBufferSubData(GL_ARRAY_BUFFER, 0, arrlen(points) * sizeof(Point), points);

    float time = (float) SDL_GetTicks() / 1000.0f;
    glUniform1f(glGetUniformLocation(shader_program.id, "time"), time);

    glDrawArrays(GL_POINTS, 0, arrlen(points));

    SDL_GL_SwapWindow(window);
    return SDL_APP_CONTINUE;
}


void SDL_AppQuit(void* appstate, SDL_AppResult result)
{
    SDL_GL_DestroyContext(gl_context);
    arrfree(points);
}