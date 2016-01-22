#include "Conservator.h"

Conservator::Conservator(float shape, float scale)
    :shape(shape)
    ,scale(scale)
{}

Conservator::Conservator(const Conservator& c)
    :shape(c.shape)
    ,scale(c.scale)
    ,defaultRandomEngine(c.defaultRandomEngine)
{}

Conservator& Conservator::operator= (const Conservator& c)
{
    shape = c.shape;
    scale = c.scale;
    defaultRandomEngine = c.defaultRandomEngine;

    return *this;
}

float Conservator::getShape()
{
    return shape;
}

float Conservator::getScale()
{
    return scale;
}

void Conservator::setDefaultRandomEngine(std::shared_ptr<std::default_random_engine> defaultRandomEngine)
{
    this->defaultRandomEngine = defaultRandomEngine;
}

float Conservator::getRepairTime()
{
    std::weibull_distribution<float> distribution(shape, scale);

    return distribution(*defaultRandomEngine);
}
