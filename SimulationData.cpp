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
