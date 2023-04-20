//
// Created by Fisher on 4/20/23.
//

#include "logger/RegexSearchFilter.h"

#include <utility>

RegexSearchFilter::RegexSearchFilter(std::regex pattern) : pattern(std::move(pattern)) {
}

bool RegexSearchFilter::match(const std::string &text) {
    std::smatch smatch;
    return std::regex_search(text, smatch, pattern);
}
