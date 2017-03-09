#pragma once

class Entity {
    public:
        Entity() {
            position.first = 0;
            position.second = 0;
            width = 0;
            height = 0;
        }

        virtual void Update(double dt) {
            sprite->Update(dt);
        }
        virtual void HandleEvent(SDL_Event *e) {}
        virtual void Draw() {
            std::cout << position.first << " " << position.second << std::endl;
            sprite->Draw(position.first, position.second);
        }
        virtual void DrawCentered() {
            sprite->Draw(position.first - sprite->width/2, position.second - sprite->height/2);
        }

        void SetPosition(int x, int y) {
            position.first = x;
            position.second = y;
        }

        void SetSprite(Sprite *sprite) {
            this->sprite = sprite;
        }

        bool CheckCollision(Entity *other) {
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
        Sprite *sprite;
        int width, height;
};
