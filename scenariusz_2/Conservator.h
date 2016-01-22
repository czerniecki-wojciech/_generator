#ifndef CONSERVATOR_H
#define CONSERVATOR_H

#include <random>
#include <memory>

class Conservator
{
protected:
    float shape;
    float scale;
    std::shared_ptr<std::default_random_engine> defaultRandomEngine;

public:
    Conservator() = default;
    Conservator(float shape, float scale);
    Conservator(const Conservator& c);
    Conservator& operator= (const Conservator& c);

    float getShape();
    float getScale();

    float getRepairTime();
    void setDefaultRandomEngine(std::shared_ptr<std::default_random_engine> defaultRandomEngine);
};

#endif // CONSERVATOR_H
