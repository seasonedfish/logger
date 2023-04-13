//
// Created by Fisher on 4/6/23.
//

#ifndef LOGGER_LOGGER_H
#define LOGGER_LOGGER_H

#include <mutex>

class Logger {
private:
    static Logger *instance;
    static std::mutex mutex;
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
};

#endif //LOGGER_LOGGER_H
