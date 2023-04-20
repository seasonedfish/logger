//
// Created by Fisher on 4/20/23.
//

#include "logger/CStreamHandler.h"

CStreamHandler::CStreamHandler(std::FILE *f) : file(f) {
}

void CStreamHandler::emit(std::string message) {
    std::fprintf(file, "%s\n", message.c_str());
}
