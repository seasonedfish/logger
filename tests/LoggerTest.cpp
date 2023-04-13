//
// Created by Fisher on 4/13/23.
//

#include <thread>
#include <future>
#include <cstdint>

#include "gtest/gtest.h"

#include "logger/Logger.h"

Logger *Logger::instance{nullptr};
std::mutex Logger::mutex;

uintptr_t threadedLoggerAddress() {
    // Following code emulates slow initialization.
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    Logger *logger = Logger::getInstance();
    return reinterpret_cast<std::uintptr_t>(logger);
}

TEST(LoggerTest, isThreadSafe) {
    std::future<uintptr_t> future0 = std::async(&threadedLoggerAddress);
    std::future<uintptr_t> future1 = std::async(&threadedLoggerAddress);
    std::future<uintptr_t> future2 = std::async(&threadedLoggerAddress);

    auto address0 = future0.get();
    auto address1 = future1.get();
    auto address2 = future2.get();

    ASSERT_EQ(address0, address1) << "Loggers in multiple threads should be the same";
    ASSERT_EQ(address0, address2) << "Loggers in multiple threads should be the same";
}

