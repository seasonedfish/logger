//
// Created by Fisher on 4/20/23.
//

#ifndef LOGGER_REGEXSEARCHFILTER_H
#define LOGGER_REGEXSEARCHFILTER_H

#include <regex>

#include "AbstractFilter.h"

class RegexSearchFilter : public AbstractFilter {
private:
    std::regex pattern;
public:
    explicit RegexSearchFilter(std::regex);

    bool match(const std::string &text) override;
};

#endif //LOGGER_REGEXSEARCHFILTER_H
