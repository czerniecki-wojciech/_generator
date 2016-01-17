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
    std::shared_ptr<SimulationInputData> simulationInputData = generator.generate();

    cout << simulationInputData;

    //simulator
    std::shared_ptr<SimulationData> simulationData = std::make_shared<SimulationData>(simulationInputData);
    cout << simulationData;

    cout << simulationData->getTotalElementsCost() << std::endl;

    return 0;
}

