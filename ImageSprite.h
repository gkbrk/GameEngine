#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Engine.h"
#include "Sprite.h"

class ImageSprite: public Sprite {
    public:
        ImageSprite(std::string path) {
            image = IMG_Load(path.c_str());
            width = image->w;
            height = image->h;
        }

        void Draw() {
            SDL_Rect spriteRect;
            spriteRect.x = position.first;
            spriteRect.y = position.second;
            SDL_BlitSurface(image, NULL, Engine::surface, &spriteRect);
        }

        SDL_Surface *image;
};
