#include <iostream>
#include <thread>

#include "devices/DeviceA.h"
#include "devices/DeviceB.h"
#include "EventQueue.h"
#include "events/DataEvent.h"
#include "events/StartedEvent.h"
#include "events/WorkDoneEvent.h"



void read(const std::shared_ptr<Device>& device, const int& callsCount, EventQueue& queue) {
    queue.push(std::make_shared<StartedEvent>(StartedEvent(device)));

    int i = 0;
    while (i < callsCount) {
        queue.push(std::make_shared<DataEvent>(DataEvent(device)));
        i++;
    }

    queue.push(std::make_shared<WorkDoneEvent>(WorkDoneEvent(device)));
}


void process(EventQueue& queue) {
    bool deviceADone = false;
    bool deviceBDone = false;

    std::shared_ptr<const Event> event;
    while (!deviceADone || !deviceBDone) {
        event = queue.pop(std::chrono::seconds(5));

        if (event->toString() == "DeviceA work done") {
            deviceADone = true;
        }
        if (event->toString() == "DeviceB work done") {
            deviceBDone = true;
        }
        std::cout << event->toString() << "\n";
    }
}


int main() {
    EventQueue queue;
    std::shared_ptr<Device> deviceA = std::make_shared<DeviceA>();
    std::shared_ptr<Device> deviceB = std::make_shared<DeviceB>();

    std::thread thread1([&]() {
        read(deviceA, 5, queue);
    });
    std::thread thread2([&]() {
        read(deviceB, 5, queue);
    });
    
    process(queue);

    thread1.join();
    thread2.join();

    return 0;
}