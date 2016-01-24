#ifndef OUTPUTSLIMITS_H
#define OUTPUTSLIMITS_H

#include <utility>

#include "MinMaxBoundLimitError.h"

class OutputsLimits
{
public:
    std::pair<float, float> shapeLimit;
    std::pair<float, float> scaleLimit;

    OutputsLimits(float shapeLimitMin, float shapeLimitMax, float scaleLimitMin, float scaleLimitMax);
    OutputsLimits(std::pair<float, float> shapeLimit, std::pair<float, float> scaleLimit);
    OutputsLimits(const OutputsLimits& ol);
    OutputsLimits& operator= (const OutputsLimits&);
};

#endif // OUTPUTSLIMITS_H
