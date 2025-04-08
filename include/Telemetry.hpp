#ifndef TELEMETRY_HPP
#define TTELEMETRY_HPP

#pragma once

#include <string>

struct Telemetry{
    float altitude; // km
    float velocity; // km/s
    float battery; // %
    float temperature; // C
    float pitch, yaw, roll; //orientation in degress
};

// function to simulate random telemetry data
Telemetry generateTelemetry(const Telemetry& previous);

#endif