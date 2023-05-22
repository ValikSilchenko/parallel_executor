#pragma once

#include "Device.h"

class DeviceB : public Device {
public:
    std::string getName() const override {
        return "DeviceB";
    }

    std::string getDataAsString() const override {
        return std::to_string(rand() * 1000 % 198) + ";" + std::to_string(rand() * 1000 % 198) + ";" +
               std::to_string(rand() * 1000 % 198);
    }
};
