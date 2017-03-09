#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <map>
#include <iostream>

namespace ImageStore {
    std::map<std::string, SDL_Surface*> imageMap;

    void LoadImage(std::string path, std::string key) {
        std::map<std::string, SDL_Surface*>::iterator it;

        it = imageMap.find(key);
        if (it == imageMap.end()) {
            SDL_Surface *raw_img = IMG_Load(path.c_str());
            if (raw_img == NULL) {
                std::cerr << "Cannot load image: " << path << std::endl;
                Engine::Exit(1);
            }
            // Optimize image
            SDL_Surface *image = SDL_ConvertSurface(raw_img, Engine::surface->format, 0);
            SDL_FreeSurface(raw_img);

            imageMap[key] = image;
        }
    }

    void LoadImage(std::string path) {
        LoadImage(path, path);
    }

    SDL_Surface *GetImage(std::string key) {
        return imageMap[key];
    }
}
