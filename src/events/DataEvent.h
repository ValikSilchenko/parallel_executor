#pragma once

#include "DeviceEvent.h"

class DataEvent : public DeviceEvent {
public:
    std::string toString() override {
        return DeviceEvent::toString();
    };
};
