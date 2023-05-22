#pragma once

#include <queue>
#include <mutex>
#include <condition_variable>
#include <thread>

#include "events/Event.h"

class EventQueue
{
public:
    // Положить сообщение в очередь
    void push(const std::shared_ptr<const Event>& event);

    // Удалить сообщение из очереди и вернуть его. По истечении duration, если очередь пуста, вернуть пустой указатель
    std::shared_ptr<const Event> pop(const std::chrono::seconds& duration);
private:
    std::queue<std::shared_ptr<const Event>> queue;
    std::mutex mtx;
    std::condition_variable cv;
};
