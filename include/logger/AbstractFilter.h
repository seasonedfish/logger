//
// Created by Fisher on 4/13/23.
//

#ifndef LOGGER_ABSTRACTFILTER_H
#define LOGGER_ABSTRACTFILTER_H

#include <string>

class AbstractFilter {
public:
    virtual ~AbstractFilter() = default;
    virtual bool match(const std::string& text) = 0;
};

#endif //LOGGER_ABSTRACTFILTER_H
