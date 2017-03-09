#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Engine.h"
#include "Sprite.h"
#include "ImageStore.h"

class ImageSprite: public Sprite {
    public:
        ImageSprite(std::string path) {
            ImageStore::LoadImage(path);
            image = ImageStore::GetImage(path);
            width = image->w;
            height = image->h;
        }

        void Draw(int x, int y) {
            SDL_Rect spriteRect;
            spriteRect.x = x;
            spriteRect.y = y;
            SDL_BlitSurface(image, NULL, Engine::surface, &spriteRect);
        }

        SDL_Surface *image;
};
