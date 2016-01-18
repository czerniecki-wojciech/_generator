#ifndef ADAPTIVE_H
#define ADAPTIVE_H

#include "SimulationData.h"
#include "SimulationResult.h"
#include "Simulation.h"

class Adaptive
{
public:
    Adaptive(SimulationData simulationData, uint maxCost, uint maxNumberOfConservators, uint reapets);
};

#endif // ADAPTIVE_H
