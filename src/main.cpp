#include "Telemetry.hpp"
#include "Display.hpp"

#include <thread>
#include <chrono>
#include <iostream>
#include <vector>
#include <string>


//ANSI color codes
const std::string RESET = "\033[0m";
const std::string GREEN = "\033[32m";
const std::string RED = "\033[31m";
const std::string YELLOW = "\033[33m";
const std::string BLUE = "\033[34m";
const std::string CYAN = "\033[36m";
const std::string BOLD = "\033[1m";


struct User {
    std::string name;
    std::string id;
};

User authenticateUser(){
    User user;
    std::cout << "=== AUTHENTICATION REQUIRED ===\n";
    std::cout << "Enter your name: ";
    std::getline(std::cin, user.name);

    std::cout << "Enter your ID: ";
    std::getline(std::cin, user.id);

    std::cout << "Authenticating";

    for(int i = 0; i < 3; i++){
        std::cout << ".";
        std::cout.flush();
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
    std::cout << "\n\n";
    return user;
};

void startupSequence(const User& user){
    using namespace std::chrono_literals;

    std::vector<std::string> steps = {
        BLUE + "[BOOT]" + RESET + " Initializing Spacecraft Telemetry System...",
        YELLOW + "[SYSCHK]" + RESET + " Checking onboard diagnostics...",
        CYAN + "[COMM]" + RESET + " Establishing connection with spacecraft...",
        CYAN + "[COMM]" + RESET + " Link established. Signal strength: " + GREEN + "GOOD" + RESET + ".",
        BLUE + "[INIT]" + RESET + " Loading telemetry modules...",
        RED + "[SEC]" + RESET + " Authenticating user: " + user.name + " [ID: " + user.id + "]...",
        GREEN + "[SEC]" + RESET + " Access granted.",
        BLUE + "[CONF]" + RESET + " Loading system configuration...",
        GREEN + "[ENG]" + RESET + " Engine sensors calibrated.",
        GREEN + "[ENV]" + RESET + " Environmental systems stable.",
        GREEN + "[INFO]" + RESET + " All systems nominal.",
        "",
        "T-minus 3 seconds to live data stream..."
    };

    for (const auto& line : steps){
        std::cout << line << std::endl;
        std::this_thread::sleep_for(2s);
    }

    //countdown
    for (int i = 3; i>=1; --i){
        std::cout << ">> " << i << "..." << std::endl;
        std::this_thread::sleep_for(3s);
    }

    std::cout << ">> TELEMETRY ONLINE\n";
    std::cout << "--------------------------------------------------\n";
    std::this_thread::sleep_for(1500ms);

}

int main() {

    User user = authenticateUser();
    startupSequence(user);

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
