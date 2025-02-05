/* Enable SDL3 callbacks instead of using main() */
#define SDL_MAIN_USE_CALLBACKS 1

#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

static SDL_Window *window = NULL;
static SDL_Renderer *renderer = NULL;

SDL_AppResult SDL_AppInit(void **appstate, int argc, char *argv[])
{
    if (!SDL_Init(SDL_INIT_VIDEO)) 
    {
        return SDL_APP_FAILURE;
    }

    if (!SDL_CreateWindowAndRenderer("funny window", 1280, 720, 0, &window, &renderer)) 
    {
        return SDL_APP_FAILURE;
    }

    return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppEvent(void *appstate, SDL_Event *event)
{
    if (event->type == SDL_EVENT_QUIT) 
    {
        return SDL_APP_SUCCESS;
    }
    return SDL_APP_CONTINUE;
}

/* Runs every frame */
SDL_AppResult SDL_AppIterate(void *appstate)
{
    return SDL_APP_CONTINUE;
}


void SDL_AppQuit(void *appstate, SDL_AppResult result)
{
    // quit time
}