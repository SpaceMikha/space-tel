#include "Telemetry.hpp"
#include <random>

Telemetry generateTelemetry(){
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_real_distribution<float> altitude(400.0, 500.0);
    std::uniform_real_distribution<float> velocity(400.0, 500.0);
    std::uniform_real_distribution<float> battery(20.0, 100.0);
    std::uniform_real_distribution<float> temperature(-20.0, 85.0);
    std::uniform_real_distribution<float> orientation(-180.0, 180.0);

    return Telemetry{
        altitude(gen),
        velocity(gen),
        battery(gen),
        temperature(gen),
        orientation(gen),
        orientation(gen),
        orientation(gen),
    };
    
}