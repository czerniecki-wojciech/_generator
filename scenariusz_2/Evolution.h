#ifndef EVOLUTION_H
#define EVOLUTION_H

#include <chrono>

#include "limits"
#include "SimulationData.h"
#include "SimulationResult.h"
#include "PermutationGenerator.h"
#include "PermutationModificator.h"
#include "Simulation.h"


class Evolution
{
public:
    Evolution(SimulationData simulationData, uint maxCost, uint maxNumberOfConservators, uint repeats, uint individuals, uint generations);
};

#endif // EVOLUTION_H
