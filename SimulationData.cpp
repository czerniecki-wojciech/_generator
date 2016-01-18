#include "SimulationData.h"

SimulationData::SimulationData(SimulationInputData simulationInputData)
    :SimulationInputData(simulationInputData)
    ,defaultRandomEngine(std::make_shared<std::default_random_engine>())
{
    repairKitSet = RepairKitSet(this->elements, defaultRandomEngine);
    conservator.setDefaultRandomEngine(defaultRandomEngine);
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
    this->defaultRandomEngine = sd.defaultRandomEngine;

    return *this;
}

std::ostream& operator<< (std::ostream& ostream, SimulationData& sd) {
    /*std::for_each(sd.elements.begin(), sd.elements.end(), [&ostream](Element& element) {
        ostream << element;
    });*/

    ostream << sd.repairKitSet << std::endl;

    return ostream;
}

uint SimulationData::getElementsNum()
{
    return repairKitSet.getElementsNum();
}

uint SimulationData::getTotalElementsCost()
{
    return repairKitSet.getTotalElementsCost();
}

uint SimulationData::getTotalCostOfElement(uint num) {
    return repairKitSet.getTotalCostOfElement(num);
}

uint SimulationData::getNumberOfBackupsElemets(uint num) {
    return repairKitSet.getNumberOfBackupsElemets(num);
}

float SimulationData::getDamageTime(uint num) {
    return repairKitSet.getDamageTime(num);
}

float SimulationData::getRepairTime() {
    return conservator.getRepairTime();
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
