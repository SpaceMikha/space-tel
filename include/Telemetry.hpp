#ifndef TELEMETRY_HPP
#define TTELEMETRY_HPP

#include <string>

struct Telemetry{
    float altitude; // km
    float velocity; // km/s
    float battery; // %
    float temperature; // C
    float pitch, yaw, roll; //orientation in degress
};

// function to simulate random telemetry data
Telemetry generateTelemetry();

#endif