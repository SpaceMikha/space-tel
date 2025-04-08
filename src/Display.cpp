#include "Display.hpp"
#include <iostream>
#include <iomanip>
#include <chrono>
#include <ctime>

#ifdef _WIN34
#include <windows.h>
#else
#include <unistd.h>
#endif

void clearScreen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}


void renderTelemetry(const Telemetry& data){
    clearScreen();

    //get the curent time
    auto now = std::chrono::system_clock::now();
    std::time_t timeNow = std::chrono::system_clock::to_time_t(now);

    std::cout << "+-----------------------------------------------------+\n";
    std::cout << "|           SPACECRAFT TELEMETRY DASHBOARD           |\n";
    std::cout << "+-----------------------------------------------------+\n";

    std::cout << "| Time:        " << std::put_time(std::localtime(&timeNow), "%Y-%m-%d %H:%M:%S") << "         |\n";
    std::cout << "| Altitude:    " << std::fixed << std::setprecision(2) << data.altitude << " km                               |\n";
    std::cout << "| Velocity:    " << data.velocity << " km/s                              |\n";
    std::cout << "| Battery:     " << data.battery << " %                                  |\n";
    std::cout << "| Temperature: " << data.temperature << " °C                                |\n";
    std::cout << "| Orientation: Pitch: " << data.pitch
              << "° | Yaw: " << data.yaw
              << "° | Roll: " << data.roll << "°   |\n";

    std::cout << "+-----------------------------------------------------+\n";

    //alert 
    if (data.temperature > 60.0f)
        std::cout << "| ALERT: High temperature!                            |\n";
    else if (data.battery < 25.0f)
        std::cout << "| ALERT: Battery low!                                 |\n";
    else
        std::cout << "| Status: All systems nominal.                        |\n";

    std::cout << "+-----------------------------------------------------+\n";

    
}