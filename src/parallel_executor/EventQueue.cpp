#include "EventQueue.h"

void EventQueue::push(const std::shared_ptr<const Event> &event) {

}

std::shared_ptr<const Event> EventQueue::pop(const std::chrono::seconds &duration) {
    return std::shared_ptr<const Event>();
}
