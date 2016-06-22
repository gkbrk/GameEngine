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

        bool CheckCollision(Sprite *other) {
            // Sides of the first sprite
            int leftA = position.first;
            int rightA = position.first + width;
            int topA = position.second;
            int bottomA = position.second + height;

            // Sides of the second sprite
            int leftB = other->position.first;
            int rightB = other->position.first + width;
            int topB = other->position.second;
            int bottomB = other->position.second + height;

            //Detect collision
            if (bottomA <= topB || topA >= bottomB || rightA <= leftB || leftA >= rightB){
                return false;
            }else{
                return true;
            }
        }

        std::pair<double, double> position;
        int width, height;
};
