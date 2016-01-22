#include "SimulationInputDataGenerator.h"

SimulationInputDataGenerator::SimulationInputDataGenerator(uint elementsNum, std::shared_ptr<OutputsLimits> outputsLimits, std::pair<uint, uint> priceLimit, std::shared_ptr<ConservatorLimits> conservatorLimits)
{
    this->elementsNum = elementsNum;
    this->priceLimit = priceLimit;
    this->outputsLimits = outputsLimits;
    this->conservatorLimits = conservatorLimits;
    std::srand(std::time(0));
}

SimulationInputData SimulationInputDataGenerator::generate() {
    SimulationInputData simulationData(this->elementsNum);
    simulationData.erase();

    float shape;
    float scale;
    int price;

    for(uint i=0; i<this->elementsNum; ++i)
    {
        shape = static_cast<float>(rand()%90) / 10.0f + 1.0f;
        scale = static_cast<float>(rand()%90) / 10.0f + 1.0f;
        price = rand()%(priceLimit.second - priceLimit.first) + priceLimit.first;

        simulationData.createAndAddNewElement(shape, scale, price);
    }

    shape = static_cast<float>(rand()%90) / 10.0f + 1.0f;
    scale = static_cast<float>(rand()%90) / 10.0f + 1.0f;

    simulationData.addConservator(shape, scale);

    return simulationData;
}

