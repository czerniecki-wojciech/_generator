#include "Simulation.h"

uint Simulation::findLowestTimeIndex(std::vector<float>& events) {
    float lowest = std::numeric_limits<float>::max();
    uint index = 0;

    for(uint i=0; i<events.size(); ++i)
    {
        if(events.at(i) < lowest)
        {
            lowest = events.at(i);
            index = i;
        }
    }

    return index;
}

void Simulation::runSingleSimulation(SimulationData sd)
{
    float workingTime = 0.0f;
    float totalTime = 0.0f;

    float money = moneyForConservators;

    std::vector<float> events;

    for(uint i=0; i<sd.getElementsNum(); ++i)
    {
        events.push_back(sd.getDamageTime(i));
    }

    while(money > 0)
    {
        uint currentEvent = findLowestTimeIndex(events);
        float timeToAdvance = events.at(currentEvent);

        if(timeToAdvance * float(numberOfConservators) >= money) {
            workingTime += money / float(numberOfConservators);
            totalTime += money / float(numberOfConservators);
            money = 0;
        } else {
            for(uint i=0; i<events.size(); ++i)
            {
                events.at(i) = events.at(i) - timeToAdvance;
            }
            money -= timeToAdvance * float(numberOfConservators);
            workingTime += timeToAdvance;
            totalTime += timeToAdvance;

            if(sd.isReplaceKitForElement(currentEvent))
            {
                sd.takeReplaceKitForElement(currentEvent);
                events.at(currentEvent) = sd.getDamageTime(currentEvent);
            } else {
				money = 0.0f;
                break;
            }

            float repairTime = sd.getRepairTime() / float(numberOfConservators);
            if(repairTime * float(numberOfConservators) <= money)
            {
                money -= repairTime * float(numberOfConservators);
                totalTime += repairTime;
            } else {
                money = 0.0f;
                totalTime += money / float(numberOfConservators);
            }
        }
    }

    results.push_back(SimulationResult(workingTime, totalTime));
}

Simulation::Simulation(SimulationData sd, uint moneyForConservators, uint numberOfConservators, uint repeat)
    :moneyForConservators(moneyForConservators)
    ,repeat(repeat)
    ,numberOfConservators(numberOfConservators)
    ,simulationData(sd)
{}

Simulation::Simulation(const Simulation& s)
    :results(s.results.size())
    ,moneyForConservators(s.moneyForConservators)
    ,repeat(s.repeat)
    ,numberOfConservators(s.numberOfConservators)
    ,simulationData(s.simulationData)
{
    std::copy(s.results.begin(), s.results.end(), results.begin());
}

Simulation& Simulation::operator= (const Simulation& s)
{
    results = std::vector<SimulationResult>(s.results.size());
    moneyForConservators = s.moneyForConservators;
    repeat = s.repeat;
    numberOfConservators = s.numberOfConservators;
    simulationData = simulationData;

    std::copy(s.results.begin(), s.results.end(), results.begin());

    return *this;
}

SimulationResult Simulation::getAvaragedResult()
{
    float sumWorkingTime = 0.0f;
    float sumTotalTime = 0.0f;

    for(uint n=0; n<repeat; ++n)
    {
        runSingleSimulation(simulationData);
    }

    std::for_each(results.begin(), results.end(), [&sumWorkingTime, &sumTotalTime] (SimulationResult v) {
        sumWorkingTime += v.workingTime;
        sumTotalTime += v.totalTime;
    });

    return SimulationResult(sumWorkingTime/float(repeat), sumTotalTime/float(repeat));
}
