#pragma once

#include <memory>

#include "Event.h"
#include "devices/Device.h"

class DeviceEvent : public Event {
public:
    explicit DeviceEvent(const std::shared_ptr<Device> &device) : device_(device) {};

    virtual ~DeviceEvent() = default;;
protected:
    std::shared_ptr<Device> device_;
};
