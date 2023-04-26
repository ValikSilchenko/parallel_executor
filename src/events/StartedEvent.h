#pragma once

#include "DeviceEvent.h"

class StartedEvent : public DeviceEvent {
public:
    std::string toString() override {
        return DeviceEvent::toString();
    };
};
