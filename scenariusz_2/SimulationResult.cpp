#include "SimulationResult.h"

SimulationResult::SimulationResult(float workingTime, float totalTime, int missingElement)
	:workingTime(workingTime)
	,totalTime(totalTime)
	,missingElement(missingElement)
{}

SimulationResult::SimulationResult(const SimulationResult& sr)
    :workingTime(sr.workingTime)
    ,totalTime(sr.totalTime)
	,missingElement(sr.missingElement)
{}

SimulationResult& SimulationResult::operator= (const SimulationResult& sr)
{
    workingTime = sr.workingTime;
    totalTime = sr.totalTime;
	missingElement = sr.missingElement;

	return *this;
}
