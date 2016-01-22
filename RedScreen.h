#pragma once

#include "GameState.h"
#include "Engine.h"
#include "Mouse.h"
#include <iostream>

class RedScreen: public GameState {
    public:
        void Draw() {
            SDL_FillRect(Engine::surface, NULL, SDL_MapRGB(Engine::surface->format, 255, 0, 0));
        }

        void Update(double dt) {
            std::cout << Mouse::x << "|" << Mouse::y << std::endl;
        }
};
