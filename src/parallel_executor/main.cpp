#include <iostream>
#include <thread>

#include "devices/DeviceA.h"
#include "devices/DeviceB.h"
#include "EventQueue.h"
#include "events/DataEvent.h"
#include "events/StartedEvent.h"
#include "events/WorkDoneEvent.h"



void read(const std::shared_ptr<Device>& device, int callsCount, EventQueue& queue, int secondsToRead) {
    queue.push(std::make_shared<StartedEvent>(StartedEvent(device)));

    int i = 0;
    while (i != callsCount) {
        std::this_thread::sleep_for(std::chrono::seconds(secondsToRead));
        queue.push(std::make_shared<DataEvent>(DataEvent(device)));
        i++;
    }

    queue.push(std::make_shared<WorkDoneEvent>(WorkDoneEvent(device)));
}


void process(EventQueue& queue) {
    int devicesDoneCount = 0;

    std::shared_ptr<const Event> event;
    int devicesError = 0;
    while (devicesDoneCount < 2) {
        event = queue.pop(std::chrono::seconds(5));

        if (event == nullptr) {
            std::cerr << "Error while device reading\n";
            devicesError++;
            if (devicesError + devicesDoneCount == 2)
                return;
        } else {
            devicesError--;
        }

        if (dynamic_cast<const WorkDoneEvent*>(event.get()) != nullptr) {
            devicesDoneCount++;
        }
        std::cout << event->toString() << "\n";
    }
}


void run(int deviceACyclesCount = -1, int deviceBCyclesCount = -1) {
    EventQueue queue;
    std::shared_ptr<Device> deviceA = std::make_shared<DeviceA>();
    std::shared_ptr<Device> deviceB = std::make_shared<DeviceB>();

    std::thread deviceAThread([&]() {
        read(deviceA, deviceACyclesCount, queue, 1);
    });
    std::thread deviceBThread([&]() {
        read(deviceB, deviceBCyclesCount, queue, 5);
    });

    process(queue);

    deviceAThread.join();
    deviceBThread.join();
}

int main(int argc, char** argv) {
    if (argc != 3) {
        std::cerr << "Program must have 2 arguments: <DeviceA read cycles count>, <DeviceB read cycles count>\n";
        std::cerr << "For set device in normal mode pass -1 as read cycles count\n";
        return -1;
    }

    int countA = std::stoi(argv[1]);
    int countB = std::stoi(argv[2]);

    run(countA, countB);

    return 0;
}