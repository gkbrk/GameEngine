#pragma once

class Sprite {
    public:
        Sprite() {
            position.first = 0;
            position.second = 0;
            width = 0;
            height = 0;
        }

        virtual void Update(double dt) {}
        virtual void HandleEvent(SDL_Event *e) {}
        virtual void Draw() {}

        void SetPosition(int x, int y) {
            position.first = x;
            position.second = y;
        }

        void SetCenteredPosition(int x, int y) {
            SetPosition(x-width/2, y-height/2);
        }

        std::pair<double, double> position;
        int width, height;
};
