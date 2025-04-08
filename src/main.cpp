#include "Telemetry.hpp"
#include "Display.hpp"
#include <thread>
#include <chrono>

int main() {
    while (true) {
        Telemetry data = generateTelemetry();
        renderTelemetry(data);

        // Wait for 1 second
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    return 0;
}
