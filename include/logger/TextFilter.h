//
// Created by Fisher on 4/13/23.
//

#ifndef LOGGER_TEXTFILTER_H
#define LOGGER_TEXTFILTER_H

#include <string>

#include "AbstractFilter.h"

class TextFilter : public AbstractFilter {
private:
    std::string pattern;
public:
    explicit TextFilter(std::string pattern);

    bool match(const std::string &text) override;
};

#endif //LOGGER_TEXTFILTER_H
