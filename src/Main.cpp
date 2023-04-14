//
// Created by Fisher on 4/13/23.
//

#include <iostream>

#include "logger/Logger.h"
#include "logger/StreamHandler.h"
#include "logger/TextFilter.h"

int main() {
    StreamHandler handler(&std::cerr);
    TextFilter filter("warning");
    Logger *logger = Logger::getInstance({&filter}, {&handler});

    logger->log("warning! c++ detected");
    logger->log("a regular message");
    logger->log("cool it works");
}
