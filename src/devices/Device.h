#pragma once

#include <string>

class Device {
public:
    Device() = default;
    virtual ~Device() = default;

    virtual std::string getName() = 0;

    virtual std::string getDataAsString() = 0;
};
