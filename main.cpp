#include <iostream>

#include "SimulationInputDataGenerator.h"
#include "SimulationData.h"
#include "PermutationIterator.h"
#include "Simulation.h"

using namespace std;

int main()
{
    //generator
    std::pair<uint, uint> priceLimit = std::make_pair<uint, uint>(1, 10);
    std::pair<uint, uint> shapeLimit = std::make_pair<uint, uint>(1, 10);
    std::pair<uint, uint> scaleLimit = std::make_pair<uint, uint>(1, 10);

    std::shared_ptr<OutputsLimits> outputsLimits = std::make_shared<OutputsLimits>(shapeLimit, scaleLimit);

    SimulationInputDataGenerator generator(3, outputsLimits, priceLimit);
    SimulationInputData simulationInputData = generator.generate();

    //simulator
    SimulationData simulationData(simulationInputData);

//    simulationData.setNumOfReplaceKitForElement(0 ,2);
//    simulationData.setNumOfReplaceKitForElement(1 ,3);

    cout << simulationInputData;
    cout << simulationData;

    uint maxCost = 20;
    uint maxNumberOfConservators = 2;

    PermutationIterator pi(simulationData, maxCost);
    while(pi.get().getTotalElementsCost() <= maxCost)
    {
        //sym
        Simulation simulation(pi.get(), maxCost - pi.get().getTotalElementsCost(), 1, 1);
        std::cout << "sym for " << pi.get().getTotalElementsCost() << std::endl;
        std::cout << "avg result " << simulation.getAvaragedResult() << std::endl;
        ++pi;
    }

    return 0;
}

