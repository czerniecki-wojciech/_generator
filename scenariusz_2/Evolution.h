#ifndef EVOLUTION_H
#define EVOLUTION_H

#include "limits"
#include "SimulationData.h"
#include "SimulationResult.h"
#include "PermutationGenerator.h"
#include "Simulation.h"


class Evolution
{
public:
    Evolution(SimulationData simulationData, uint maxCost, uint maxNumberOfConservators, uint reapets, uint individuals, uint generations);
};

#endif // EVOLUTION_H
