#pragma once

#include "GameState.h"
#include "Engine.h"
#include "Mouse.h"
#include "Text.h"
#include "ImageSprite.h"
#include <sstream>

class DebugScreen: public GameState {
    public:
        DebugScreen() {
            mouse_coords = new Text("/usr/share/fonts/TTF/DejaVuSans.ttf", 18);
            mouse_coords->SetPosition(15, 15);

            crosshair = new ImageSprite("Resources/sprites/crosshair.png");
        }

        void Draw() {
            SDL_FillRect(Engine::surface, NULL, SDL_MapRGB(Engine::surface->format, 0, 0, 0));
            mouse_coords->Draw();
            crosshair->Draw();
        }

        void Update(double dt) {
            std::ostringstream mouse_text;
            mouse_text << "X: " << Mouse::x << " | Y: " << Mouse::y;
            mouse_coords->SetText(mouse_text.str());

            crosshair->SetCenteredPosition(Mouse::x, Mouse::y);
        }

        Text *mouse_coords;
        ImageSprite *crosshair;
};
