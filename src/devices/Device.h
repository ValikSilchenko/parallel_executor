#pragma once

#include <string>

class Device {
public:
    Device() = default;
    virtual ~Device() = default;

    virtual std::string getName() const = 0;

    virtual std::string getDataAsString() const = 0;
};
