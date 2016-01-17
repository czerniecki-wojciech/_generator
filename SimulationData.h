#ifndef SIMULATIONDATA_H
#define SIMULATIONDATA_H

#include <random>

#include "SimulationInputData.h"
#include "RepairKitSet.h"

class SimulationData : private SimulationInputData
{
private:
    friend std::ostream& operator<< (std::ostream& ostream, SimulationData* sd);

    std::shared_ptr<RepairKitSet> repairKitSet;
    std::shared_ptr<std::default_random_engine> defaultRandomEngine;
public:
    SimulationData(std::shared_ptr<SimulationInputData> simulationInputData);
    SimulationData(std::string filename); //TODO

    uint getTotalElementsCost();

    bool isReplaceKitForElement(uint num);
    void takeReplaceKitForElement(uint num);
    void setNumOfReplaceKitForElement(uint num, uint elementsNum);
};

#endif // SIMULATIONDATA_H
