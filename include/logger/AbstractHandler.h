//
// Created by Fisher on 4/13/23.
//

#ifndef LOGGER_ABSTRACTHANDLER_H
#define LOGGER_ABSTRACTHANDLER_H

#include <string>

class AbstractHandler {
public:
    virtual ~AbstractHandler() = default;
    virtual void emit(std::string) = 0;
};

#endif //LOGGER_ABSTRACTHANDLER_H
