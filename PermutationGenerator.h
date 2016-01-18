#ifndef PERMUTATIONGENERATOR_H
#define PERMUTATIONGENERATOR_H

#include "SimulationData.h"
#include <random>

class PermutationGenerator
{
private:
    SimulationData simulationData;

    SimulationData nextPermutation();

    uint maxCost;
public:
    PermutationGenerator(SimulationData& simulationData, uint maxCost);

    SimulationData operator++();
};

#endif // PERMUTATIONGENERATOR_H
