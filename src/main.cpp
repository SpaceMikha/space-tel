#include "Telemetry.hpp"
#include "Display.hpp"
#include <thread>
#include <chrono>

int main() {

    Telemetry state = {
        420.0f, //alt
        7.2f, //vel
        100.0f, //bat
        25.0f, //temp
        0.0f, 0.0f, 0.0f //putch, yaw, roll
    };

    while (true) {
        Telemetry data = generateTelemetry(state);
        renderTelemetry(data);

        // Wait for 10 seconds
        std::this_thread::sleep_for(std::chrono::seconds(10));
    }

    return 0;
}
