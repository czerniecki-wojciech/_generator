#include "PermutationIterator.h"

PermutationIterator::PermutationIterator(SimulationData& simulationData, uint maxCost)
    :simulationData(simulationData)
    ,maxCost(maxCost)
{}

PermutationIterator::PermutationIterator(const PermutationIterator& pi)
    :simulationData(pi.simulationData)
    ,maxCost(pi.maxCost)
{}

PermutationIterator& PermutationIterator::operator= (const PermutationIterator& pi) {
    this->simulationData = pi.simulationData;
    this->maxCost = pi.maxCost;

    return *this;
}

SimulationData PermutationIterator::nextPermutation()
{
    uint elementNum = simulationData.getElementsNum();

    uint current = 0;
    uint next = current + 1;

    uint numberOfBackupElements = simulationData.getNumberOfBackupsElemets(current);
    simulationData.setNumOfReplaceKitForElement(current, numberOfBackupElements + 1);

    while(simulationData.getTotalElementsCost() > maxCost && next < elementNum)
    {
        simulationData.setNumOfReplaceKitForElement(current, 0);

        uint nextState = simulationData.getNumberOfBackupsElemets(next);
        simulationData.setNumOfReplaceKitForElement(next, nextState + 1);

        current = next;
        next += 1;
    }

    std::cout << "getTotalElementsCost " << simulationData.getTotalElementsCost() << std::endl;
    std::cout << simulationData;


    return this->simulationData;
}

SimulationData PermutationIterator::get()
{
    return this->simulationData;
}

void PermutationIterator::operator++() {
    nextPermutation();
}
