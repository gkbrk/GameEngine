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
            mouse_coords = new Text("/usr/share/fonts/TTF/DejaVuSans.ttf", 15);
            mouse_coords->SetPosition(15, 15);

            fps = new Text("/usr/share/fonts/TTF/DejaVuSans.ttf", 15);
            fps->SetPosition(15, 35);

            crosshair = new ImageSprite("Resources/sprites/crosshair.png");
        }

        void Draw() {
            SDL_FillRect(Engine::surface, NULL, SDL_MapRGB(Engine::surface->format, 0, 0, 0));
            mouse_coords->Draw();
            fps->Draw();

            SDL_Rect x_line;
            x_line.x = Mouse::x;
            x_line.y = 0;
            x_line.w = 2;
            x_line.h = Engine::height;
            SDL_FillRect(Engine::surface, &x_line, SDL_MapRGB(Engine::surface->format, 255, 255, 255));
            
            SDL_Rect y_line;
            y_line.x = 0;
            y_line.y = Mouse::y;
            y_line.w = Engine::width;
            y_line.h = 2;
            SDL_FillRect(Engine::surface, &y_line, SDL_MapRGB(Engine::surface->format, 255, 255, 255));
            
            crosshair->Draw();
        }

        void Update(double dt) {
            std::ostringstream mouse_text;
            mouse_text << "X: " << Mouse::x << " | Y: " << Mouse::y;
            mouse_coords->SetText(mouse_text.str());

            std::ostringstream fps_text;
            fps_text << "FPS: " << Engine::averageFPS;
            fps->SetText(fps_text.str());

            crosshair->SetCenteredPosition(Mouse::x, Mouse::y);

            if (Mouse::x > 1360 && Mouse::y > 760) {
                stateFinished = true;
            }
        }

        Text *mouse_coords;
        Text *fps;
        ImageSprite *crosshair;
};
