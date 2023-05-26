#include "EventQueue.h"

void EventQueue::push(const std::shared_ptr<const Event> &event) {
    std::lock_guard<std::mutex> lock(mtx);
    queue.push(event);
    cv.notify_one();
}

std::shared_ptr<const Event> EventQueue::pop(const std::chrono::seconds &duration) {
    std::unique_lock<std::mutex> lock(mtx);
    bool condition = cv.wait_for(lock, duration, [=] {
        return !queue.empty();
    });

    if (condition) {
        auto element = queue.front();
        queue.pop();
        return element;
    }
    return nullptr;
}
