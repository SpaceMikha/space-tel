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

struct EPSData{
    float voltage;
    float current;
    float chargePercent;
    float solarInput;
    float timeRemaining;
};

// function to simulate random telemetry data
Telemetry generateTelemetry(const Telemetry& previous);

// simulate next eps reading
EPSData generateEPSData(const EPSData& previous);

#endif