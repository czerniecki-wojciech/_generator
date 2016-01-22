#ifndef SIMULATION_H
#define SIMULATION_H

#include <limits>

#include "SimulationData.h"
#include "SimulationResult.h"

class Simulation
{
private:
    std::vector<SimulationResult> results;
    float moneyForConservators;
    uint repeat;
    uint numberOfConservators;
    SimulationData simulationData;

    void runSingleSimulation(SimulationData sd);
    uint findLowestTimeIndex(std::vector<float>& events);
public:
    Simulation() = default;
    Simulation(SimulationData sd, uint moneyForConservators, uint numberOfConservators, uint repeat);
    Simulation(const Simulation& s);
    Simulation& operator= (const Simulation& s);

    SimulationResult getAvaragedResult();
};

#endif // SIMULATION_H
