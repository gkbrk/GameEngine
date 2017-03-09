#pragma once

class Sprite {
    public:
        Sprite() {
            width = 0;
            height = 0;
        }

        virtual void Update(double dt) {}
        virtual void HandleEvent(SDL_Event *e) {}
        virtual void Draw(int x, int y) {}

        int width, height;
};
