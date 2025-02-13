/* GLAD */
#include <glad/glad.h>

/* SRC */
#include "app.h"

App::App()
{
    /* Initializing SDL and relevant SDL subsystems */
    if(!SDL_Init(SDL_INIT_VIDEO)) 
    {
        exit(1);
    }

    /* Creating a window with SDL */
    window = SDL_CreateWindow("paint tool", window_width, window_height, SDL_WINDOW_OPENGL);
    if(!window)
    {
        SDL_Log("Failed to create window: %s", SDL_GetError());
        exit(1);
    }

    /* Configuring OpenGL context */
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    
    /* Creating an OpenGL context */
    gl_context = SDL_GL_CreateContext(window);
    if(!gl_context)
    {
        SDL_Log("Failed to create OpenGL context: %s", SDL_GetError());
        exit(1);
    }

    /* Initializing GLAD for OpenGL function pointers */
    if(!gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress)) 
    {
        SDL_Log("Failed to initialize glad.");
        exit(1);
    }

    /* Creating a renderer object */
    renderer = std::make_unique<Renderer>();
}

App::~App()
{
    if(window){SDL_DestroyWindow(window);}
    if(gl_context){SDL_GL_DestroyContext(gl_context);}
    SDL_Quit();
}

void App::run()
{
    bool is_running = true;
    SDL_Event event;

    while(is_running) 
    {
        while(SDL_PollEvent(&event)) 
        {
            if (event.type == SDL_EVENT_QUIT) 
            {
                is_running = false;
            }
        }

        glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        SDL_GL_SwapWindow(window);
    }
}