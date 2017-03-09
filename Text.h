#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "Engine.h"
#include "Sprite.h"
#include "Entity.h"
class Text: public Entity {
    public:
        Text(std::string fontPath, int fontSize) {
            font = TTF_OpenFont(fontPath.c_str(), fontSize);
            color = {255, 255, 255};
            renderedText = TTF_RenderText_Solid(font, " ", color);
            text = " ";
        }

        ~Text() {
            TTF_CloseFont(font);
            SDL_FreeSurface(renderedText);
        }

        void SetText(std::string text, SDL_Color color) {
            if (text != this->text) {
                SDL_FreeSurface(renderedText);
                renderedText = TTF_RenderText_Solid(font, text.c_str(), color);
                width = renderedText->w;
                height = renderedText->h;
                this->text = text;
            }
        }

        void SetText(std::string text) {
            SetText(text, color);
        }

        void SetColor(SDL_Color color) {
            this->color = color;
        }

        void SetColor(int r, int g, int b) {
            color = {(Uint8)r, (Uint8)g, (Uint8)b};
        }

        void Draw() {
            SDL_Rect drawRect;
            drawRect.x = position.first;
            drawRect.y = position.second;
            SDL_BlitSurface(renderedText, NULL, Engine::surface, &drawRect);
        }

        TTF_Font *font;
        SDL_Color color;
        std::string text;
        SDL_Surface *renderedText;
};
