#include "SimulationData.h"

SimulationData::SimulationData(SimulationInputData simulationInputData)
    :SimulationInputData(simulationInputData)
    ,defaultRandomEngine(std::make_shared<std::default_random_engine>())
{
    repairKitSet = RepairKitSet(this->elements, defaultRandomEngine);
}

SimulationData::SimulationData(const SimulationData& sd)
    :SimulationInputData(sd)
    ,repairKitSet(sd.repairKitSet)
{
    defaultRandomEngine = defaultRandomEngine;
}

SimulationData& SimulationData::operator= (const SimulationData& sd)
{
    SimulationInputData::operator=(sd);
    this->repairKitSet = sd.repairKitSet;
    this->defaultRandomEngine = defaultRandomEngine;

    return *this;
}

std::ostream& operator<< (std::ostream& ostream, SimulationData& sd) {
    std::for_each(sd.elements.begin(), sd.elements.end(), [&ostream](Element& element) {
        ostream << element;
    });

    ostream << sd.repairKitSet << std::endl;

    return ostream;
}

uint SimulationData::getTotalElementsCost()
{
    return repairKitSet.getTotalElementsCost();
}

uint SimulationData::getTotalCostOfElement(uint num) {
    return repairKitSet.getTotalCostOfElement(num);
}

bool SimulationData::isReplaceKitForElement(uint num) {
    return repairKitSet.isReplaceKitForElement(num);
}

void SimulationData::takeReplaceKitForElement(uint num) {
    repairKitSet.takeReplaceKitForElement(num);
}

void SimulationData::setNumOfReplaceKitForElement(uint num, uint elementsNum) {
    repairKitSet.setNumOfReplaceKitForElement(num, elementsNum);
}
