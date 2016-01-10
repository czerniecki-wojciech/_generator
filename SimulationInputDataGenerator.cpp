#include "SimulationInputDataGenerator.h"

SimulationInputDataGenerator::SimulationInputDataGenerator(uint elementsNum, std::pair<uint, uint> costLimit)
{
    this->elementsNum = elementsNum;
    this->costLimit = costLimit;
    std::srand(std::time(0));
}

std::shared_ptr<SimulationInputData> SimulationInputDataGenerator::generate() {
    std::shared_ptr<SimulationInputData> simulationData = std::make_shared<SimulationInputData>(this->elementsNum);
    simulationData->erase();

    for(uint i=0; i<this->elementsNum; ++i)
    {
        float shape = static_cast<float>(rand()%90) / 10.0f + 1.0f;
        float scale = static_cast<float>(rand()%90) / 10.0f + 1.0f;
        int price = rand()%(costLimit.second - costLimit.first) + costLimit.first;
        simulationData->createAndAddNewElement(shape, scale, price);
    }

    return simulationData;
}

