#include "SimulationData.h"

SimulationData::SimulationData(std::shared_ptr<SimulationInputData> simulationInputData)
    :SimulationInputData(simulationInputData)
    ,defaultRandomEngine(std::make_shared<std::default_random_engine>())
{
    repairKitSet = std::make_shared<RepairKitSet>(this->elements, defaultRandomEngine);
}

std::ostream& operator<< (std::ostream& ostream, SimulationData* sd) {
    std::for_each(sd->elements.begin(), sd->elements.end(), [&ostream](Element& element) {
        ostream << element;
    });

    ostream << sd->repairKitSet << std::endl;

    return ostream;
}

uint SimulationData::getTotalElementsCost()
{
    return repairKitSet->getTotalElementsCost();
}

uint SimulationData::getTotalCostOfElement(uint num) {
    return repairKitSet->getTotalCostOfElement(num);
}

bool SimulationData::isReplaceKitForElement(uint num) {
    return repairKitSet->isReplaceKitForElement(num);
}

void SimulationData::takeReplaceKitForElement(uint num) {
    repairKitSet->takeReplaceKitForElement(num);
}

void SimulationData::setNumOfReplaceKitForElement(uint num, uint elementsNum) {
    repairKitSet->setNumOfReplaceKitForElement(num, elementsNum);
}
