#pragma once

#include "Device.h"

class DeviceA : public Device {
public:
    std::string getName() const override {
        return "DeviceA";
    }

    std::string getDataAsString() const override {
        return "string";
    }
};
