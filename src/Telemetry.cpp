#include "Telemetry.hpp"
#include <random>
#include <cmath>

Telemetry generateTelemetry(const Telemetry& previous){
    std::random_device rd;
    std::mt19937 gen(rd());

    
    std::uniform_real_distribution<float> delta_altitude(-1.0, 1.5);
    std::uniform_real_distribution<float> delta_velocity(-0.1, 0.1);
    std::uniform_real_distribution<float> delta_battery(-0.05, 0.005);
    std::uniform_real_distribution<float> delta_temp(-0.5, 0.5);
    std::uniform_real_distribution<float> delta_orientation(-2.0, 2.0);

    Telemetry next;

    next.altitude    = std::fmax(0.0f, previous.altitude + delta_altitude(gen));
    next.velocity    = std::fmax(0.0f, previous.velocity + delta_velocity(gen));
    next.battery     = std::fmax(0.0f, previous.battery + delta_battery(gen));
    next.temperature = previous.temperature + delta_temp(gen);
    next.pitch       = previous.pitch + delta_orientation(gen);
    next.yaw         = previous.yaw + delta_orientation(gen);
    next.roll        = previous.roll + delta_orientation(gen);

    return next;
}