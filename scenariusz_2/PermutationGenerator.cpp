#include "PermutationGenerator.h"

PermutationGenerator::PermutationGenerator(SimulationData& simulationData, uint maxCost)
    :simulationData(simulationData)
    ,maxCost(maxCost)
{}

SimulationData PermutationGenerator::nextPermutation()
{
    SimulationData sd(simulationData);
    for(uint i=0; i< simulationData.getElementsNum(); ++i)
    {
        uint availableFin = maxCost - sd.getTotalElementsCost();
        sd.setNumOfReplaceKitForElement(i, 1);
		if (availableFin > 0 && sd.getTotalCostOfElement(i) < availableFin)
		{
			uint repairKitsNum = rand() % (availableFin / sd.getTotalCostOfElement(i));
			sd.setNumOfReplaceKitForElement(i, repairKitsNum);
		}
		else {
			sd.setNumOfReplaceKitForElement(i, 0);
		}
    }

    return sd;
}

SimulationData PermutationGenerator::operator++()
{
    return nextPermutation();
}
