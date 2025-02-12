/* Enable SDL3 callbacks instead of using main() */
#define SDL_MAIN_USE_CALLBACKS 1

/* STDLIB */
#include <stack>

/* SDL3 */
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

/* GLAD */
#include <glad/glad.h>

/* GLM */
#include <glm/vec2.hpp>

/* Source */
#include <layers/layer.h>
#include <commands/command.h>
#include <tools/brush_tool/brush_tool.h>

#define MAX_POINTS 1000000

static SDL_Window* window = NULL;
static SDL_GLContext gl_context = NULL;

int window_width = 1280;
int window_height = 720;

unsigned int VAO, VBO;

Layer layer;
BrushTool brush;

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

    return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppEvent(void* appstate, SDL_Event *event)
{
    if(event->type == SDL_EVENT_QUIT) // Allowing safe exit
    {
        return SDL_APP_SUCCESS;
    }

    if(event->type == SDL_EVENT_MOUSE_BUTTON_DOWN && event->button.button == SDL_BUTTON_LEFT)
    {
        glm::vec2 point = {(event->button.x / (float)window_width) * 2.0f - 1.0f, 1.0f - (event->button.y / (float)window_height) * 2.0f};
        brush.on_press(point, &layer);
    }
    else if(event->type == SDL_EVENT_MOUSE_BUTTON_UP && event->button.button == SDL_BUTTON_LEFT)
    {
        glm::vec2 point = {(event->button.x / (float)window_width) * 2.0f - 1.0f, 1.0f - (event->button.y / (float)window_height) * 2.0f};
        brush.on_release(point, &layer);
    }

    if(event->type == SDL_EVENT_MOUSE_MOTION)
    {
        glm::vec2 point = {(event->button.x / (float)window_width) * 2.0f - 1.0f, 1.0f - (event->button.y / (float)window_height) * 2.0f};
        brush.on_hold(point, &layer);
    }

    return SDL_APP_CONTINUE;
}

/* Runs every frame */
SDL_AppResult SDL_AppIterate(void* appstate)
{
    glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glPointSize(5.0f);

    SDL_GL_SwapWindow(window);
    return SDL_APP_CONTINUE;
}


void SDL_AppQuit(void* appstate, SDL_AppResult result)
{
    SDL_GL_DestroyContext(gl_context);
}