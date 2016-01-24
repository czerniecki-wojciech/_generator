#pragma once

#include <random>

#include "myTypes.h"
#include "SimulationData.h"

class PermutationModificator
{
private:
	uint maxCost;
public:
	PermutationModificator(uint maxCost);
	PermutationModificator(const PermutationModificator& pm);
	PermutationModificator& operator= (const PermutationModificator& pm);

	SimulationData modifyPermutation(SimulationData& simulationData);
};

