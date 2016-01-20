#pragma once

#include "GameState.h"
#include "Engine.h"
#include "Mouse.h"
#include "Text.h"
#include <sstream>

class DebugScreen: public GameState {
    public:
        DebugScreen() {
            mouse_coords = new Text("Resources/fonts/fantasque.ttf", 18);
            mouse_coords->SetPosition(15, 15);
        }

        void Draw() {
            SDL_FillRect(Engine::surface, NULL, SDL_MapRGB(Engine::surface->format, 0, 0, 0));
            mouse_coords->Draw();
        }

        void Update(double dt) {
            std::ostringstream mouse_text;
            mouse_text << "X: " << Mouse::x << " | Y: " << Mouse::y;
            mouse_coords->SetText(mouse_text.str());
        }

        Text *mouse_coords;
};
