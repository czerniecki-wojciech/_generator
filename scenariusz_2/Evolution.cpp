#include "Evolution.h"

Evolution::Evolution(SimulationData simulationData, uint maxCost, uint maxNumberOfConservators, uint reapets, uint individuals, uint generations)
{
    std::vector<std::vector<std::pair<SimulationResult, SimulationData>>> bruteforceByNumOfConservators;
    for(uint numOfConservators=1; numOfConservators<=maxNumberOfConservators; ++numOfConservators)
    {
        bruteforceByNumOfConservators.push_back(std::vector<std::pair<SimulationResult, SimulationData>>());
    }

    /*
     * PermutationIterator pi(simulationData, maxCost);
    while(pi.get().getTotalElementsCost() <= maxCost)
    {
        for(uint numOfConservators=1; numOfConservators<=maxNumberOfConservators; ++numOfConservators)
        {
            Simulation simulation(pi.get(), maxCost - pi.get().getTotalElementsCost(), numOfConservators, reapets);
            bruteforceByNumOfConservators.at(numOfConservators-1)
                    .push_back(std::pair<SimulationResult, SimulationData>(simulation.getAvaragedResult(),
                                                                           pi.get()));
        }
        ++pi;
    }*/


    PermutationGenerator pg(simulationData, maxCost);

    for(uint i=0; i<generations * individuals; ++i)
    {
        for(uint numOfConservators=1; numOfConservators<=maxNumberOfConservators; ++numOfConservators)
        {
            SimulationData sd = ++pg;
            Simulation simulation(sd, maxCost - sd.getTotalElementsCost(), numOfConservators, reapets);
            bruteforceByNumOfConservators.at(numOfConservators-1)
                    .push_back(std::pair<SimulationResult, SimulationData>(simulation.getAvaragedResult(),
                                                                           sd));
        }
    }

    float bestWorkingTime = 0;
    float bestTotalTime = 0;
    float bestPercentOfWorkingTime = 0.0f;

    uint bestWorkingTimeNumOfConservators = 1;
    uint bestTotalTimeNumOfConservators = 1;
    uint bestPercentOfWorkingTimeNumOfConservators = 1;

    uint indexBestWorkingTime = 0;
    uint indexBestTotalTime = 0;
    uint indexBestPercentOfWorkingTime = 0;

    for(uint numOfConservators=1; numOfConservators<=maxNumberOfConservators; ++numOfConservators)
    {
        uint size = bruteforceByNumOfConservators.at(numOfConservators-1).size();

        for(uint i = 0; i<size; ++i)
        {
            SimulationResult current = bruteforceByNumOfConservators.at(numOfConservators-1).at(i).first;

            if(current.workingTime >= bestWorkingTime)
            {
                bestWorkingTime = current.workingTime;
                indexBestWorkingTime = i;
                bestWorkingTimeNumOfConservators = numOfConservators;
            }

            if(current.totalTime >= bestTotalTime)
            {
                bestTotalTime = current.totalTime;
                indexBestTotalTime = i;
                bestTotalTimeNumOfConservators = numOfConservators;
            }

            if(current.workingTime / current.totalTime >= bestPercentOfWorkingTime)
            {
                bestPercentOfWorkingTime = current.workingTime / current.totalTime;
                indexBestPercentOfWorkingTime = i;
                bestPercentOfWorkingTimeNumOfConservators = numOfConservators;
            }
        }
    }

	float workingTime = bruteforceByNumOfConservators.at(bestWorkingTimeNumOfConservators - 1).at(indexBestWorkingTime).first.workingTime;
	float totalTime = bruteforceByNumOfConservators.at(bestWorkingTimeNumOfConservators - 1).at(indexBestWorkingTime).first.totalTime;

	std::cout << "============================================================" << std::endl;
	std::cout << "Evolution(maxCost=" << maxCost << ", maxNumberOfConservators=" << maxNumberOfConservators << ", reapets=" << reapets << ", individuals=" << individuals << ", generations=" << generations << ")" << std::endl;
	std::cout << "============================================================" << std::endl;

	std::cout << "Best working time: " << workingTime << "(" << workingTime << "/" << totalTime << ") [" << workingTime / totalTime * 100 << "%]" << std::endl;
    std::cout << "Numebr of conservators: " << bestWorkingTimeNumOfConservators << std::endl;
    std::cout << "SimulationData:" << std::endl;
    std::cout << bruteforceByNumOfConservators.at(bestWorkingTimeNumOfConservators-1).at(indexBestWorkingTime).second << std::endl;

	workingTime = bruteforceByNumOfConservators.at(bestTotalTimeNumOfConservators - 1).at(indexBestTotalTime).first.workingTime;
	totalTime = bruteforceByNumOfConservators.at(bestTotalTimeNumOfConservators - 1).at(indexBestTotalTime).first.totalTime;

	std::cout << "Best total time: " << totalTime << "(" << workingTime << "/" << totalTime << ") [" << workingTime / totalTime * 100 << "%]" << std::endl;
    std::cout << "Numebr of conservators: " << bestTotalTimeNumOfConservators << std::endl;
    std::cout << "SimulationData:" << std::endl;
    std::cout << bruteforceByNumOfConservators.at(bestTotalTimeNumOfConservators - 1).at(indexBestTotalTime).second << std::endl;
	std::cout << "============================================================" << std::endl;
}
