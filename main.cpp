#include <iostream>

#include "SimulationInputDataGenerator.h"

using namespace std;

int main()
{
    std::pair<uint, uint> priceLimit = std::make_pair<uint, uint>(1, 10);
    std::pair<uint, uint> shapeLimit = std::make_pair<uint, uint>(1, 10);
    std::pair<uint, uint> scaleLimit = std::make_pair<uint, uint>(1, 10);

    std::shared_ptr<OutputsLimits> outputsLimits = std::make_shared<OutputsLimits>(shapeLimit, scaleLimit);

    SimulationInputDataGenerator generator(10, outputsLimits, priceLimit);
    std::shared_ptr<SimulationInputData> simulationInputData = generator.generate();

    cout << simulationInputData;



    return 0;
}

