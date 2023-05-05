#pragma once

#include "DeviceEvent.h"

class WorkDoneEvent : public DeviceEvent {
public:
    explicit WorkDoneEvent(const std::shared_ptr<Device>& device) : DeviceEvent(device) {};

    std::string toString() const override {
        return device_->getName() + " work done";
    };
};
