#ifndef SIMULATION_H
#define SIMULATION_H

#include <limits>

#include "SimulationData.h"

class Simulation
{
private:
    std::vector<float> results;
    float moneyForConservators;
    uint repeat;
    uint numberOfConservators;
    SimulationData simulationData;

    void runSingleSimulation(SimulationData sd,  uint numberOfConservators);
public:
    Simulation() = default;
    Simulation(SimulationData sd, uint moneyForConservators, uint numberOfConservators, uint repeat);
    Simulation(const Simulation& s);
    Simulation& operator= (const Simulation& s);

    float getAvaragedResult();
};

#endif // SIMULATION_H
