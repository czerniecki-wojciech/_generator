#include <iostream>

#include "SimulationInputDataGenerator.h"
#include "SimulationData.h"
#include "PermutationIterator.h"
#include "Simulation.h"
#include "BruteForce.h"
#include "Evolution.h"
#include "EvolutionHelper.h"
#include "Adaptive.h"

using namespace std;

int main()
{
    //generator
    std::pair<uint, uint> priceLimit = std::make_pair<uint, uint>(1, 10);
    std::pair<uint, uint> shapeLimit = std::make_pair<uint, uint>(1, 10);
    std::pair<uint, uint> scaleLimit = std::make_pair<uint, uint>(1, 10);

    std::shared_ptr<OutputsLimits> outputsLimits = std::make_shared<OutputsLimits>(shapeLimit, scaleLimit);
    std::shared_ptr<ConservatorLimits> conservatorLimits = std::make_shared<ConservatorLimits>(shapeLimit, scaleLimit);

    SimulationInputDataGenerator generator(4, outputsLimits, priceLimit, conservatorLimits);
    SimulationInputData simulationInputData = generator.generate();

    //simulator
    SimulationData simulationData(simulationInputData);

//    simulationData.setNumOfReplaceKitForElement(0 ,2);
//    simulationData.setNumOfReplaceKitForElement(1 ,3);

    cout << simulationInputData;

    uint maxCost = 50;
    uint maxNumberOfConservators = 3;
    uint repets = 100;

	EvolutionHelper eh(maxCost, simulationData);

    uint numOfIndividuals = eh.getIndividualsNum();
    uint numOfGenerations = eh.getGenerationNum();

    BruteForce bf(simulationData, maxCost, maxNumberOfConservators, repets);
    Evolution ev(simulationData, maxCost, maxNumberOfConservators, repets, numOfIndividuals, numOfGenerations);
	Adaptive ad(simulationData, maxCost, maxNumberOfConservators, repets);

	system("pause");

    return 0;
}

