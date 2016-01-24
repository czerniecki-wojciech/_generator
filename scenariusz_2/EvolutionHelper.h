#pragma once

#include <cmath>

#include "myTypes.h"
#include "SimulationData.h"

class EvolutionHelper
{
private:
	uint maxCost;
	SimulationData sd;
public:
	EvolutionHelper(uint maxCost, SimulationData simulationData);
	EvolutionHelper(const EvolutionHelper& eh);
	EvolutionHelper& operator= (const EvolutionHelper& eh);

	uint getGenerationNum();
	uint getIndividualsNum();
};

