#ifndef BRUTEFORCE_H
#define BRUTEFORCE_H

#include <chrono>

#include "SimulationData.h"
#include "SimulationResult.h"
#include "PermutationIterator.h"
#include "Simulation.h"

class BruteForce
{
public:
    BruteForce(SimulationData simulationData, uint maxCost, uint maxNumberOfConservators, uint repeats);
};

#endif // BRUTEFORCE_H
