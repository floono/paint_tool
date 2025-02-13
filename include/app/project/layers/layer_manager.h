#pragma once

/* STD */
#include <list>

/* SRC */
#include "app/project/layers/layer.h"

class LayerManager
{
    private:
        std::list<Layer> layers;
    public:
        LayerManager();
        ~LayerManager();
        void add_layer();
        void remove_layer();
        void move_layer();
};