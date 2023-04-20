//
// Created by Fisher on 4/13/23.
//

#ifndef LOGGER_SEARCHFILTER_H
#define LOGGER_SEARCHFILTER_H

#include <string>

#include "AbstractFilter.h"

class SearchFilter : public AbstractFilter {
private:
    std::string pattern;
public:
    explicit SearchFilter(std::string pattern);

    bool match(const std::string &text) override;
};

#endif //LOGGER_SEARCHFILTER_H
