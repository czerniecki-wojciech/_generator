#include "SimulationResult.h"

SimulationResult::SimulationResult(float workingTime, float totalTime)
    :workingTime(workingTime)
    ,totalTime(totalTime)
{}

SimulationResult::SimulationResult(const SimulationResult& sr)
    :workingTime(sr.workingTime)
    ,totalTime(sr.totalTime)
{}

SimulationResult& SimulationResult::operator= (const SimulationResult& sr)
{
    workingTime = sr.workingTime;
    totalTime = sr.totalTime;
}
