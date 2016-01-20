#pragma once

#include "GameState.h"
#include "Engine.h"

class RedScreen: public GameState {
    public:
        void Draw() {
            SDL_FillRect(Engine::surface, NULL, SDL_MapRGB(Engine::surface->format, 255, 0, 0));
        }
};
