//
// Created by Fisher on 4/13/23.
//

#include <thread>

#include "gtest/gtest.h"

#include "logger/Logger.h"

TEST(LoggerTest, isSingleton) {
    Logger *logger0 = Logger::getInstance({}, {});
    Logger *logger1 = Logger::getInstance({}, {});

    ASSERT_EQ(logger0, logger1) << "Multiple calls to getInstance should return the same logger";
}
