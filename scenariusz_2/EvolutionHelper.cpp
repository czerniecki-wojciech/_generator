#include "EvolutionHelper.h"

EvolutionHelper::EvolutionHelper(uint maxCost, SimulationData simulationData)
	:sd(simulationData)
	,maxCost(maxCost)
{}

EvolutionHelper::EvolutionHelper(const EvolutionHelper& eh)
	:sd(eh.sd)
	,maxCost(eh.maxCost)
{}

EvolutionHelper& EvolutionHelper::operator= (const EvolutionHelper& eh)
{
	sd = eh.sd;
	maxCost = eh.maxCost;

	return *this;
}

uint EvolutionHelper::getGenerationNum()
{
	uint elementsNum = sd.getElementsNum();
	uint result = 1;

	for (uint i = 1; i < elementsNum; ++i)
	{
		sd.setNumOfReplaceKitForElement(i, 1);
		result *= maxCost / sd.getTotalCostOfElement(i);
	}

	result /= elementsNum;

	return sqrt(result);
}

uint EvolutionHelper::getIndividualsNum()
{
	uint elementsNum = sd.getElementsNum();
	uint result = 1;

	for (uint i = 1; i < elementsNum; ++i)
	{
		sd.setNumOfReplaceKitForElement(i, 1);
		result *= maxCost / sd.getTotalCostOfElement(i);
	}

	result /= elementsNum;

	return sqrt(result);
}
