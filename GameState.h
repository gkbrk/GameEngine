#pragma once

#include <SDL2/SDL.h>

class GameState {
    public:
        virtual ~GameState() {}
        virtual void HandleEvent(SDL_Event *e) {}
        virtual void Update(double dt) {}
        virtual void Draw() {}

        bool stateFinished = false;
};
