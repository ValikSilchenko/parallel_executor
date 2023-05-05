#include "EventQueue.h"

void EventQueue::push(const std::shared_ptr<const Event> &event) {
   std::lock_guard<std::mutex> lock(mtx);

   queue.push(event);
}

std::shared_ptr<const Event> EventQueue::pop(const std::chrono::seconds &duration) {
    std::lock_guard<std::mutex> lock(mtx);

    auto element = queue.front();
    queue.pop();

    return element;
}
