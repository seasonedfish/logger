//
// Created by Fisher on 4/13/23.
//

#include "logger/SearchFilter.h"

#include <utility>

SearchFilter::SearchFilter(std::string pattern) : pattern(std::move(pattern)) {
}

bool SearchFilter::match(const std::string &text) {
    return text.find(pattern) != std::string::npos;
}
