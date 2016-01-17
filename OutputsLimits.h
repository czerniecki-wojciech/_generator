#ifndef OUTPUTSLIMITS_H
#define OUTPUTSLIMITS_H

#include <utility>

#include "MinMaxBoundLimitError.h"

class OutputsLimits
{
public:
    std::pair<int, int> shapeLimit;
    std::pair<int, int> scaleLimit;

    OutputsLimits(int shapeLimitMin, int shapeLimitMax, int scaleLimitMin, int scaleLimitMax);
    OutputsLimits(std::pair<int, int> shapeLimit, std::pair<int, int> scaleLimit);
    OutputsLimits(const OutputsLimits& ol);
    OutputsLimits& operator= (const OutputsLimits&);
};

#endif // OUTPUTSLIMITS_H
