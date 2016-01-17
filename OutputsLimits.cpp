#include "OutputsLimits.h"

OutputsLimits::OutputsLimits(int shapeLimitMin, int shapeLimitMax, int scaleLimitMin, int scaleLimitMax)
{
    if(shapeLimitMin >= shapeLimitMax || scaleLimitMin >= scaleLimitMax) {
        throw MinMaxBoundLimitError();
    }

    this->shapeLimit = std::make_pair<int, int>(int(shapeLimitMin), int(shapeLimitMax));
    this->scaleLimit = std::make_pair<int, int>(int(scaleLimitMin), int(scaleLimitMax));
}

OutputsLimits::OutputsLimits(std::pair<int, int> shapeLimit, std::pair<int, int> scaleLimit)
{
    if(shapeLimit.first >= shapeLimit.second || scaleLimit.first >= scaleLimit.second) {
        throw MinMaxBoundLimitError();
    }

    this->shapeLimit = shapeLimit;
    this->scaleLimit = scaleLimit;
}

OutputsLimits::OutputsLimits(const OutputsLimits& ol)
{
    this->shapeLimit = ol.shapeLimit;
    this->scaleLimit = ol.scaleLimit;
}

OutputsLimits& OutputsLimits::operator= (const OutputsLimits& ol)
{
    this->shapeLimit = ol.shapeLimit;
    this->scaleLimit = ol.scaleLimit;
}

