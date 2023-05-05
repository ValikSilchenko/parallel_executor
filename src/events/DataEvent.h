#pragma once

#include "DeviceEvent.h"

class DataEvent : public DeviceEvent {
public:
    explicit DataEvent(const std::shared_ptr<Device> &device) : DeviceEvent(device) {};

    std::string toString() const override {
        return device_->getDataAsString();
    };
};
