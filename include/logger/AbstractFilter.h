//
// Created by Fisher on 4/13/23.
//

#ifndef LOGGER_ABSTRACTFILTER_H
#define LOGGER_ABSTRACTFILTER_H

#include <string>

class AbstractFilter {
public:
    virtual ~AbstractFilter() = 0;
    virtual bool match(std::string) = 0;
};

#endif //LOGGER_ABSTRACTFILTER_H
