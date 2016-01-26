#include "PermutationModificator.h"


PermutationModificator::PermutationModificator(uint maxCost)
	:maxCost(maxCost)
{}

PermutationModificator::PermutationModificator(const PermutationModificator& pm)
	:maxCost(pm.maxCost)
{}

PermutationModificator& PermutationModificator::operator= (const PermutationModificator& pm)
{
	maxCost = pm.maxCost;

	return *this;
}


SimulationData PermutationModificator::modifyPermutation(SimulationData& simulationData)
{
	SimulationData sd(simulationData);
	uint elementsNum = sd.getElementsNum();

	do
	{
		sd = SimulationData(simulationData);
		uint elementIndex = rand() % elementsNum;
		uint add = rand() % 2;
		uint repairKitsForElement = sd.getNumberOfBackupsElemets(elementIndex);
		if (add)
		{
			sd.setNumOfReplaceKitForElement(elementIndex, repairKitsForElement + 1);
		}
		else if(repairKitsForElement) {
			sd.setNumOfReplaceKitForElement(elementIndex, repairKitsForElement - 1);
		}
	} while (sd.getTotalElementsCost() > maxCost);

	return sd;
}
