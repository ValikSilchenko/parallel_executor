#pragma once

#include "DeviceEvent.h"

class WorkDoneEvent : public DeviceEvent {
public:
    std::string toString() override {
        return DeviceEvent::toString();
    };
};
