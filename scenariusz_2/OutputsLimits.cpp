#include "OutputsLimits.h"

OutputsLimits::OutputsLimits(float shapeLimitMin, float shapeLimitMax, float scaleLimitMin, float scaleLimitMax)
{
    if(shapeLimitMin >= shapeLimitMax || scaleLimitMin >= scaleLimitMax) 
	{
        throw MinMaxBoundLimitError();
    }

    this->shapeLimit = std::make_pair(shapeLimitMin, shapeLimitMax);
    this->scaleLimit = std::make_pair(scaleLimitMin, scaleLimitMax);
}

OutputsLimits::OutputsLimits(std::pair<float, float> shapeLimit, std::pair<float, float> scaleLimit)
{
    if(shapeLimit.first >= shapeLimit.second || scaleLimit.first >= scaleLimit.second) 
	{
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

	return *this;
}

