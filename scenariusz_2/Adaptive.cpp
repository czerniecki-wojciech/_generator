#include "Adaptive.h"



Adaptive::Adaptive(SimulationData simulationData, uint maxCost, uint maxNumberOfConservators, uint reapets)
{
	/*std::pair<SimulationData, SimulationResult> bestWorkingTime = std::make_pair(simulationData, SimulationResult());
	std::pair<SimulationData, SimulationResult> bestTotalTime = std::make_pair(simulationData, SimulationResult());*/
	std::vector<std::pair<SimulationResult, SimulationData>> bestAvarageResultsByNumberOfConservator;

    for(uint numOfConservators=1; numOfConservators<=maxNumberOfConservators; ++numOfConservators)
    {
        SimulationData sd(simulationData);

        while(sd.getTotalElementsCost() <= maxCost)
        {
            std::vector<SimulationResult> results;
            for(uint i=0; i<reapets; ++i)
            {
                Simulation simulation(sd, maxCost - sd.getTotalElementsCost(), numOfConservators, 1);
                results.push_back(simulation.getAvaragedResult());
            }

			uint failsDueToConservatorOutOfMoney = 0;
			std::vector<int> failsDueToMissingOfElements;

			for (uint i = 0; i < sd.getElementsNum(); ++i)
				failsDueToMissingOfElements.push_back(0);

			for (uint i = 0; i < results.size(); ++i)
			{
				if (results.at(i).missingElement == -1) {
					++failsDueToConservatorOutOfMoney;
				} else {
					++failsDueToMissingOfElements[results.at(i).missingElement];
				}
			}

			auto mostTimeMissingElement = std::max_element(failsDueToMissingOfElements.begin(), failsDueToMissingOfElements.end());

			if (*mostTimeMissingElement > failsDueToConservatorOutOfMoney){
				auto index = std::distance(failsDueToMissingOfElements.begin(), mostTimeMissingElement);
				uint backupsElements = sd.getNumberOfBackupsElemets(index);
				sd.setNumOfReplaceKitForElement(index, backupsElements + 1);
				results.clear();
			} else {
				auto sumOfResults = std::accumulate(results.begin(), results.end(), SimulationResult(0.0f, 0.0f, 0), [](SimulationResult a, SimulationResult b) -> SimulationResult {
					a.workingTime += b.workingTime;
					a.totalTime += b.totalTime;
					return a;
				});

				sumOfResults.workingTime /= results.size();
				sumOfResults.totalTime /= results.size();

				/*std::cout << "WorkingTime: " << sumOfResults.workingTime << std::endl;
				std::cout << "TotalTime: " << sumOfResults.totalTime << std::endl;
				std::cout << sd << std::endl << std::endl;*/

				bestAvarageResultsByNumberOfConservator.push_back(std::make_pair(sumOfResults, sd));

				break;
			}
        }
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
	
    float bestWorkingTime = 0;
    float bestTotalTime = 0;
    float bestPercentOfWorkingTime = 0.0f;

    uint bestWorkingTimeNumOfConservators = 1;
    uint bestTotalTimeNumOfConservators = 1;

    uint indexBestWorkingTime = 0;
    uint indexBestTotalTime = 0;

    for(uint numOfConservators=1; numOfConservators<=maxNumberOfConservators; ++numOfConservators)
    {
		SimulationResult current = bestAvarageResultsByNumberOfConservator.at(numOfConservators - 1).first;
        if(current.workingTime >= bestWorkingTime)
        {
            bestWorkingTime = current.workingTime;
            bestWorkingTimeNumOfConservators = numOfConservators;
        }

        if(current.totalTime >= bestTotalTime)
        {
            bestTotalTime = current.totalTime;
            bestTotalTimeNumOfConservators = numOfConservators;
        }
    }

	float workingTime = bestAvarageResultsByNumberOfConservator.at(bestWorkingTimeNumOfConservators - 1).first.workingTime;
	float totalTime = bestAvarageResultsByNumberOfConservator.at(bestWorkingTimeNumOfConservators - 1).first.totalTime;

	std::cout << "============================================================" << std::endl;
	std::cout << "Adaptive(maxCost=" << maxCost << ", maxNumberOfConservators=" << maxNumberOfConservators << ", reapets=" << reapets << ")" << std::endl;
	std::cout << "============================================================" << std::endl;

    std::cout << "Best working time: " << workingTime << "(" << workingTime << "/" << totalTime << ") [" << workingTime/totalTime * 100 << "%]" << std::endl;
    std::cout << "Numebr of conservators: " << bestWorkingTimeNumOfConservators << std::endl;
    std::cout << "SimulationData:" << std::endl;
    std::cout << bestAvarageResultsByNumberOfConservator.at(bestWorkingTimeNumOfConservators-1).second << std::endl;

	workingTime = bestAvarageResultsByNumberOfConservator.at(bestTotalTimeNumOfConservators - 1).first.workingTime;
	totalTime = bestAvarageResultsByNumberOfConservator.at(bestTotalTimeNumOfConservators - 1).first.totalTime;

    std::cout << "Best total time: " << totalTime << "(" << workingTime << "/" << totalTime << ") [" << workingTime / totalTime * 100 << "%]" << std::endl;
    std::cout << "Numebr of conservators: " << bestTotalTimeNumOfConservators << std::endl;
    std::cout << "SimulationData:" << std::endl;
    std::cout << bestAvarageResultsByNumberOfConservator.at(bestTotalTimeNumOfConservators - 1).second << std::endl;
	std::cout << "============================================================" << std::endl;
}
