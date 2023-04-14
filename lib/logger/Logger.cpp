//
// Created by Fisher on 4/6/23.
//

#include <algorithm>
#include <utility>

#include "logger/Logger.h"

Logger *Logger::instance{nullptr};
std::mutex Logger::mutex;

Logger::Logger(std::forward_list<AbstractFilter *> filters, std::forward_list<AbstractHandler *> handlers)
    : filters(std::move(filters)), handlers(std::move(handlers)) {
}

Logger *Logger::getInstance(std::forward_list<AbstractFilter *> filters, std::forward_list<AbstractHandler *> handlers) {
    // Use lock_guard to make our singleton thread-safe.
    // https://refactoring.guru/design-patterns/singleton/cpp/example#example-1
    std::lock_guard<std::mutex> lock(mutex);

    if (instance == nullptr) {
        instance = new Logger(std::move(filters), std::move(handlers));
    }
    return instance;
}

void Logger::log(const std::string &message) {
    if (std::all_of(filters.begin(), filters.end(), [&message](AbstractFilter *f) { return f->match(message); })) {
        for (AbstractHandler *h: handlers) {
            h->emit(message);
        }
    }
}
