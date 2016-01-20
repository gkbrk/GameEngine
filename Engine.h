#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "GameState.h"
#include "DeltaTimer.h"
#include "Mouse.h"
#include <list>

namespace Engine {
    SDL_Window *window;
    SDL_Surface *surface;
    std::list<GameState*> gameStates;
    DeltaTimer timer;

    bool init_sdl() {
        if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0) {
            return false;
        }else {
            Engine::window = SDL_CreateWindow("Game Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
            if (Engine::window == NULL) {
                return false;
            }else {
                Engine::surface = SDL_GetWindowSurface(Engine::window);

                TTF_Init(); // Initialize TrueType Fonts.
                return true;
            }
        }
    }

    bool tick() {
        if (gameStates.size() > 0) {
            GameState *state = gameStates.front();

            if (!state->stateFinished) {
                // Stuff
                SDL_Event e;
                while (SDL_PollEvent(&e) != 0) {
                    if (e.type == SDL_QUIT) {
                        gameStates.clear();
                        state->stateFinished = true;
                    }

                    if (e.type == SDL_MOUSEMOTION) {
                        // Update the Mouse namespace on Mouse events
                        SDL_GetMouseState(&Mouse::x, &Mouse::y);
                    }

                    state->HandleEvent(&e);
                }

                double delta = timer.GetDelta();
                state->Update(delta);
                state->Draw();
                SDL_UpdateWindowSurface(Engine::window);
            }else {
                gameStates.pop_front();
                delete state;
            }
            return true;
        }else {
            SDL_DestroyWindow(Engine::window);
            return false;
        }
    }
}
