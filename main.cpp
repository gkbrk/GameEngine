#include "Engine.h"
#include "RedScreen.h"

int main() {
    Engine::init_sdl();
    Engine::gameStates.push_back(new RedScreen());
    
    while (true) {
        if (!Engine::tick()) {
            break;
        }
    }
}
