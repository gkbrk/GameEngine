#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Engine.h"
#include "Sprite.h"

class ImageSprite: public Sprite {
    public:
        ImageSprite(std::string path) {
            SDL_Surface *raw_image = IMG_Load(path.c_str());

            // Optimize image
            image = SDL_ConvertSurface(raw_image, Engine::surface->format, 0);
            SDL_FreeSurface(raw_image);
            
            width = image->w;
            height = image->h;
        }

        ~ImageSprite() {
            SDL_FreeSurface(image);
        }

        void Draw() {
            SDL_Rect spriteRect;
            spriteRect.x = position.first;
            spriteRect.y = position.second;
            SDL_BlitSurface(image, NULL, Engine::surface, &spriteRect);
        }

        SDL_Surface *image;
};
