#pragma once

/* STD */
#include <memory>
#include <vector>

/* SDL3 */
#include <SDL3/SDL.h>

/* SRC */
#include "app/tools/brush_tool/brush_tool.h"
#include "app/renderer/renderer.h"

class App
{
    private:
        SDL_Window* window = NULL;
        SDL_GLContext gl_context = NULL;
        
        int window_width = 1280;
        int window_height = 720;

        std::unique_ptr<Renderer> renderer;

    public:
        App();
        ~App();
        void run();
};