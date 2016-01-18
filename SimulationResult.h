#ifndef SIMULATIONRESULT_H
#define SIMULATIONRESULT_H

class SimulationResult
{
public:
    float workingTime;
    float totalTime;

    SimulationResult() = default;
    SimulationResult(float workingTime, float totalTime);
    SimulationResult(const SimulationResult& sr);
    SimulationResult& operator= (const SimulationResult& sr);
};

#endif // SIMULATIONRESULT_H
