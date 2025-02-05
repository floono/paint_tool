/* Enable SDL3 callbacks instead of using main() */
#define SDL_MAIN_USE_CALLBACKS 1

/* SDL3 Headers */
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

/* GLAD Headers */
#include <glad/glad.h>

static SDL_Window *window = NULL;
static SDL_GLContext gl_context = NULL;

SDL_AppResult SDL_AppInit(void **appstate, int argc, char *argv[])
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
    window = SDL_CreateWindow("paint tool", 1280, 720, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);
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

SDL_AppResult SDL_AppEvent(void *appstate, SDL_Event *event)
{
    if(event->type == SDL_EVENT_QUIT) 
    {
        return SDL_APP_SUCCESS;
    }
    else if (event->type == SDL_EVENT_WINDOW_RESIZED)
    {
        glViewport(0, 0, event->window.data1, event->window.data2);
    }

    return SDL_APP_CONTINUE;
}

/* Runs every frame */
SDL_AppResult SDL_AppIterate(void *appstate)
{
    glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    SDL_GL_SwapWindow(window);

    return SDL_APP_CONTINUE;
}


void SDL_AppQuit(void *appstate, SDL_AppResult result)
{
    SDL_GL_DestroyContext(gl_context);
}