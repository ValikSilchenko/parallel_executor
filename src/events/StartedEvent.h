#pragma once

#include "DeviceEvent.h"

class StartedEvent : public DeviceEvent {
public:
    explicit StartedEvent(const std::shared_ptr<Device> &device) : DeviceEvent(device) {};

    std::string toString() const override {
        return device_->getName() + " work started";
    };
};
