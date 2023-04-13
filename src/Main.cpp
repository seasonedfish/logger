//
// Created by Fisher on 4/13/23.
//

#include <thread>
#include <iostream>
#include "logger/Logger.h"

// i hate c++ bruh is there really no better way of fixing this
// https://stackoverflow.com/questions/9110487/
Logger *Logger::instance{nullptr};
std::mutex Logger::mutex;

void threadFoo() {
    // Following code emulates slow initialization.
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    Logger* logger = Logger::getInstance();
    std::cout << logger << "\n";
}

void threadBar() {
    // Following code emulates slow initialization.
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    Logger* logger = Logger::getInstance();
    std::cout << logger << "\n";
}

int main() {
    std::thread t1(threadFoo);
    std::thread t2(threadBar);
    t1.join();
    t2.join();
}
