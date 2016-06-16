#pragma once

#include "GameState.h"
#include "Engine.h"
#include "Mouse.h"
#include <iostream>

class ColorDebugScreen: public GameState {
    public:
        ColorDebugScreen() {
            red = 255;
            green = 0;
            blue = 0;
        }

        ColorDebugScreen(int r, int g, int b) {
            red = r;
            green = g;
            blue = b;
        }

        void Draw() {
            SDL_FillRect(Engine::surface, NULL, SDL_MapRGB(Engine::surface->format, red, green, blue));
        }

        void Update(double dt) {
            std::cout << Mouse::x << "|" << Mouse::y << std::endl;
        }

        void SetColor(int r, int g, int b) {
            red = r;
            green = g;
            blue = b;
        }

    private:
        int red, green, blue;
};
