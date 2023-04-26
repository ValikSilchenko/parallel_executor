cmake_minimum_required(VERSION 3.15.0)
cmake_policy(SET CMP0016 NEW)

set(CMAKE_CXX_STANDARD 17)

project(parallel_executor VERSION 1.0.0 DESCRIPTION "Синхронизация нескольких потоков исполнения через очередь сообщений на C++")

include_directories(${CMAKE_SOURCE_DIR}/src)

add_executable(${PROJECT_NAME}
        src/parallel_executor/main.cpp
        src/parallel_executor/EventQueue.h
        src/parallel_executor/EventQueue.cpp
        src/devices/Device.h
        src/devices/DeviceA.h
        src/devices/DeviceB.h
        src/events/Event.h
        src/events/DeviceEvent.h
        src/events/DataEvent.h
        src/events/WorkDoneEvent.h
        src/events/StartedEvent.h
        )

enable_testing()
add_subdirectory(test)
