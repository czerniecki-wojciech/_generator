#include <iostream>

#include "SimulationInputDataGenerator.h"
#include "SimulationData.h"

using namespace std;

int main()
{
    //generator
    std::pair<uint, uint> priceLimit = std::make_pair<uint, uint>(1, 10);
    std::pair<uint, uint> shapeLimit = std::make_pair<uint, uint>(1, 10);
    std::pair<uint, uint> scaleLimit = std::make_pair<uint, uint>(1, 10);

    std::shared_ptr<OutputsLimits> outputsLimits = std::make_shared<OutputsLimits>(shapeLimit, scaleLimit);

    SimulationInputDataGenerator generator(10, outputsLimits, priceLimit);
    SimulationInputData simulationInputData = generator.generate();

    //simulator
    SimulationData simulationData(simulationInputData);
    cout << simulationData;

    simulationData.setNumOfReplaceKitForElement(0 ,2);
    simulationData.setNumOfReplaceKitForElement(1 ,3);
    cout << simulationData;

    cout << simulationData.getTotalElementsCost() << std::endl;

    cout << simulationData.getTotalCostOfElement(0);

    return 0;
}

