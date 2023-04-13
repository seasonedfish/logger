//
// Created by Fisher on 4/6/23.
//

#ifndef LOGGER_LOGGER_H
#define LOGGER_LOGGER_H

#include <mutex>
#include <forward_list>

#include "AbstractFilter.h"
#include "AbstractHandler.h"

class Logger {
private:
    // Static fields for creating and holding on to the singleton
    static Logger *instance;
    static std::mutex mutex;

    std::forward_list<AbstractFilter *> filters;
    std::forward_list<AbstractHandler *> handlers;
protected:
    Logger() = default;
    ~Logger() = default;
public:
    /**
     * As a singleton, a Logger should not be cloneable.
     */
    Logger(Logger &other) = delete;

    /**
     * As a singleton, a Logger should not be assignable.
     */
    void operator=(const Logger &) = delete;

    /**
     * On the first run, creates a Logger object.
     * On subsequent runs, returns the the already-created Logger.
     */
    static Logger *getInstance();

    /**
     * Prints out a log message.
     */
    void log(const std::string& message);

};

#endif //LOGGER_LOGGER_H
