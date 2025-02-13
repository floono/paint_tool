#pragma once

/* STD */
#include <vector>

/* SRC */
#include "app/project/layers/layer.h"

class Project
{
    private:
        std::vector<Layer> layers;
    public:
        Project();
        ~Project();
};