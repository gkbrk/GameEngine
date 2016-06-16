#pragma once

namespace Mouse {
    int x;
    int y;

    void ShowCursor() {
        SDL_ShowCursor(1);
    }

    void HideCursor() {
        SDL_ShowCursor(0);
    }
}
