//
// Created by Fisher on 4/13/23.
//

#include <ostream>

#include "logger/StreamHandler.h"

StreamHandler::StreamHandler(std::ostream *o) : ostream(o) {
}

void StreamHandler::emit(std::string message) {
    (*ostream) << message << std::endl;
}
