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
        uint availableFin = sd.getTotalElementsCost();
        sd.setNumOfReplaceKitForElement(i, 1);
        uint repairKitsNum = rand() % (availableFin / sd.getTotalCostOfElement(i));
        sd.setNumOfReplaceKitForElement(i, repairKitsNum);
    }

    return sd;
}

SimulationData PermutationGenerator::operator++() {
    return nextPermutation();
}
