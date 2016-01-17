#ifndef SIMULATIONDATA_H
#define SIMULATIONDATA_H

#include "SimulationInputData.h"

class SimulationData : protected SimulationInputData
{
private:
    friend std::ostream& operator<< (std::ostream& ostream, SimulationData* sd);
public:
    SimulationData(std::shared_ptr<SimulationInputData> simulationInputData);
    SimulationData(std::string filename);
};

#endif // SIMULATIONDATA_H
