#pragma once

#include "Device.h"

class DeviceB : public Device {
public:
    std::string getName() override {
        return "DeviceB";
    }

    std::string getDataAsString() override {
        std::this_thread::sleep_for(std::chrono::seconds(5));
        return std::to_string(rand() * 1000 % 198) + ";" + std::to_string(rand() * 1000 % 198) + ";" +
               std::to_string(rand() * 1000 % 198);
    }
};
