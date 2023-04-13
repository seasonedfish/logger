//
// Created by Fisher on 4/13/23.
//

#include "logger/TextFilter.h"

#include <utility>

TextFilter::TextFilter(std::string pattern) : pattern(std::move(pattern)) {
}

bool TextFilter::match(const std::string &text) {
    return text.find(pattern) != std::string::npos;
}
