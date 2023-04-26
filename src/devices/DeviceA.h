#pragma once

#include "Device.h"

class DeviceA : public Device {
public:
    std::string getName() override {
        return std::__cxx11::string();
    }

    std::string getDataAsString() override {
        return std::__cxx11::string();
    }
};
