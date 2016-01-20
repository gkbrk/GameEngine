#pragma once

#include <chrono>

using namespace std::chrono;

class DeltaTimer {
    public:
        DeltaTimer() {
            lastTime = high_resolution_clock::now();
        }

        double GetDelta() {
            time_point<high_resolution_clock> now = high_resolution_clock::now();
            duration<double> diff = now - lastTime;

            lastTime = now;
            return diff.count();
        }

        time_point<high_resolution_clock> lastTime;
};
