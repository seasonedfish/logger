//
// Created by Fisher on 4/20/23.
//

#ifndef LOGGER_CSTREAMHANDLER_H
#define LOGGER_CSTREAMHANDLER_H

#include <cstdio>

#include "AbstractHandler.h"

class CStreamHandler : public AbstractHandler {
private:
    std::FILE *file;
public:
    explicit CStreamHandler(std::FILE *f);
    void emit(std::string) override;
};

#endif //LOGGER_CSTREAMHANDLER_H
