//
// Created by Fisher on 4/13/23.
//

#include <iostream>
#include "logger/Logger.h"

// i hate c++ bruh is there really no better way of fixing this
// https://stackoverflow.com/questions/9110487/
Logger *Logger::instance{nullptr};
std::mutex Logger::mutex;

int main() {
    Logger *logger = Logger::getInstance({}, {});
}
