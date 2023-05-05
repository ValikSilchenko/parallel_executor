#pragma once

#include "Device.h"

class DeviceA : public Device {
public:
    std::string getName() override {
        return "DeviceA";
    }

    std::string getDataAsString() override {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        return "string";
    }
};
