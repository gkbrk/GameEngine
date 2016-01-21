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

            SDL_Rect x_line;
            x_line.x = crosshair->position.first + crosshair->width/2;
            x_line.y = 0;
            x_line.w = 2;
            x_line.h = 600;
            SDL_FillRect(Engine::surface, &x_line, SDL_MapRGB(Engine::surface->format, 255, 255, 255));
            
            SDL_Rect y_line;
            y_line.x = 0;
            y_line.y = crosshair->position.second + crosshair->height/2;
            y_line.w = 800;
            y_line.h = 2;
            SDL_FillRect(Engine::surface, &y_line, SDL_MapRGB(Engine::surface->format, 255, 255, 255));
            
            crosshair->Draw();
        }

        void Update(double dt) {
            std::ostringstream mouse_text;
            mouse_text << "X: " << Mouse::x << " | Y: " << Mouse::y;
            mouse_coords->SetText(mouse_text.str());

            crosshair->SetCenteredPosition(Mouse::x, Mouse::y);

            if (Mouse::x > 797 && Mouse::y > 597) {
                Engine::gameStates.push_front(new SplashScreen("Resources/splash/", 2, 500));
            }
        }

        Text *mouse_coords;
        ImageSprite *crosshair;
};
