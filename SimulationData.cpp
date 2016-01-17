#include "SimulationData.h"

SimulationData::SimulationData(std::shared_ptr<SimulationInputData> simulationInputData)
    :SimulationInputData(simulationInputData)
{
}

std::ostream& operator<< (std::ostream& ostream, SimulationData* sd) {
    std::for_each(sd->elements.begin(), sd->elements.end(), [&ostream](Element& element) {
        ostream << element;
    });
    return ostream;
}
