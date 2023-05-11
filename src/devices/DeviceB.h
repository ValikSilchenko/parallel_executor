#pragma once

#include "Device.h"

class DeviceB : public Device {
public:
    std::string getName() override {
        return "DeviceB";
    }

    std::string getDataAsString() override {
        return std::to_string(rand() * 1000 % 198) + ";" + std::to_string(rand() * 1000 % 198) + ";" +
               std::to_string(rand() * 1000 % 198);
    }
};
