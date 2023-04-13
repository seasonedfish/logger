//
// Created by Fisher on 4/13/23.
//

#ifndef LOGGER_STDERRHANDLER_H
#define LOGGER_STDERRHANDLER_H

#include "AbstractHandler.h"

class StreamHandler : public AbstractHandler {
private:
    std::ostream *ostream;
public:
    explicit StreamHandler(std::ostream* o);
    void emit(std::string) override;
};
#endif //LOGGER_STDERRHANDLER_H
