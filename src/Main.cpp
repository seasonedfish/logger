//
// Created by Fisher on 4/13/23.
//

#include <iostream>

#include "logger/Logger.h"
#include "logger/StreamHandler.h"
#include "logger/SearchFilter.h"
#include "logger/RegexSearchFilter.h"

int main() {
    StreamHandler handler(&std::cerr);
    SearchFilter filter("warning");
    RegexSearchFilter regexSearchFilter(std::regex("[0-9]"));

    Logger *logger = Logger::getInstance({&filter, &regexSearchFilter}, {&handler});

    logger->log("a regular message");
    logger->log("cool it works");
    logger->log("lab6 ?????");
    logger->log("warning: i have 3 apples");
}
