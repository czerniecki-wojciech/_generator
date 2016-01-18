#include <iostream>

#include "SimulationInputDataGenerator.h"
#include "SimulationData.h"
#include "PermutationIterator.h"
#include "Simulation.h"
#include "BruteForce.h"
#include "Evolution.h"

using namespace std;

int main()
{
    //generator
    std::pair<uint, uint> priceLimit = std::make_pair<uint, uint>(1, 10);
    std::pair<uint, uint> shapeLimit = std::make_pair<uint, uint>(1, 10);
    std::pair<uint, uint> scaleLimit = std::make_pair<uint, uint>(1, 10);

    std::shared_ptr<OutputsLimits> outputsLimits = std::make_shared<OutputsLimits>(shapeLimit, scaleLimit);
    std::shared_ptr<ConservatorLimits> conservatorLimits = std::make_shared<ConservatorLimits>(shapeLimit, scaleLimit);

    SimulationInputDataGenerator generator(3, outputsLimits, priceLimit, conservatorLimits);
    SimulationInputData simulationInputData = generator.generate();

    //simulator
    SimulationData simulationData(simulationInputData);

//    simulationData.setNumOfReplaceKitForElement(0 ,2);
//    simulationData.setNumOfReplaceKitForElement(1 ,3);

    cout << simulationInputData;

    uint maxCost = 200;
    uint maxNumberOfConservators = 3;
    uint reapets = 30;

    uint numOfIndividuals = 50;
    uint numOfGenerations = 50;

    BruteForce bf(simulationData, maxCost, maxNumberOfConservators, reapets);
    Evolution ev(simulationData, maxCost, maxNumberOfConservators, reapets, numOfIndividuals, numOfGenerations);

    return 0;
}

