#pragma once

#include "Device.h"

class DeviceA : public Device {
public:
    std::string getName() override {
        return "DeviceA";
    }

    std::string getDataAsString() override {
        return "string";
    }
};
