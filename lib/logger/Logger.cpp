//
// Created by Fisher on 4/6/23.
//

#include <algorithm>

#include "logger/Logger.h"

Logger *Logger::getInstance() {
    // Use lock_guard to make our singleton thread-safe.
    // https://refactoring.guru/design-patterns/singleton/cpp/example#example-1
    std::lock_guard<std::mutex> lock(mutex);

    if (instance == nullptr) {
        instance = new Logger;
    }
    return instance;
}

void Logger::log(const std::string& message) {
    if (std::all_of(filters.begin(), filters.end(), [&message](AbstractFilter *f) {return f->match(message);})) {
        for (AbstractHandler *h : handlers) {
            h->emit(message);
        }
    }
}
