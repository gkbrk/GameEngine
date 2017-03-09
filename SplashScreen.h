#pragma once

#include <vector>
#include <sstream>
#include <iostream>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "ImageStore.h"
#include "GameState.h"

class SplashScreen: public GameState {
    public:
        SplashScreen(std::string path, int imageCount, int totalFrames) {
            frame = 0;
            this->totalFrames = totalFrames;
            for (int i=0;i<imageCount;i++) {
                std::ostringstream imagePath;
                imagePath << path << i << ".png";
                ImageStore::LoadImage(imagePath.str());
                images.push_back(ImageStore::GetImage(imagePath.str()));
            }
        }

        void Update(double dt) {
            frame += dt * 200;

            double timePerPicture = totalFrames / images.size();
            if ((frame+1) / timePerPicture >= images.size()) {
                stateFinished = true;
            }
        }

        void Draw() {
            if (!stateFinished) {
                int timePerPicture = totalFrames / images.size();
                int currentImage = (int)frame / timePerPicture;
                int alpha = (float)((int)frame % timePerPicture) / timePerPicture * 255;

                SDL_SetSurfaceBlendMode(images[currentImage], SDL_BLENDMODE_BLEND);
                SDL_SetSurfaceAlphaMod(images[currentImage], alpha);
                SDL_BlitScaled(images[currentImage], NULL, Engine::surface, NULL);
            }
        }

        std::vector<SDL_Surface*> images;
        double frame;
        int totalFrames;
};
