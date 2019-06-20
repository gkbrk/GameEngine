#include "Engine.h"
#include "SplashScreen.h"
#include "DebugScreen.h"

int main() {
    Engine::init_sdl();
    Engine::gameStates.push_back(new SplashScreen("Resources/splash/", 2, 500));
    Engine::gameStates.push_back(new DebugScreen());
    // Main loop
    while (true) {
        if (!Engine::tick()) {
            break;
        }
    }
}
