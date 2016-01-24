#include "Evolution.h"

Evolution::Evolution(SimulationData simulationData, uint maxCost, uint maxNumberOfConservators, uint repets, uint individuals, uint generations)
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
            Simulation simulation(pi.get(), maxCost - pi.get().getTotalElementsCost(), numOfConservators, repets);
            bruteforceByNumOfConservators.at(numOfConservators-1)
                    .push_back(std::pair<SimulationResult, SimulationData>(simulation.getAvaragedResult(),
                                                                           pi.get()));
        }
        ++pi;
    }*/


    PermutationGenerator pg(simulationData, maxCost);
	PermutationModificator pm(maxCost);

	std::vector<SimulationData> sdVector;


	for (uint numOfConservators = 1; numOfConservators <= maxNumberOfConservators; ++numOfConservators)
	{
		long counter = 0;
		//create population
		for (uint i = 0; i < individuals; ++i)
		{
			sdVector.push_back(++pg);
		}

		for (uint generation = 0; generation < generations; ++generation)
		{
			bruteforceByNumOfConservators.at(numOfConservators - 1).clear(); //clear results at beggining of every generations

			for (uint i = 0; i < individuals; ++i) //test every individual
			{
				Simulation simulation(sdVector.at(i), maxCost - sdVector.at(i).getTotalElementsCost(), numOfConservators, repets);
				
				bruteforceByNumOfConservators.at(numOfConservators - 1)
					.push_back(std::pair<SimulationResult, SimulationData>(simulation.getAvaragedResult(),
						sdVector.at(i)));
				++counter;
			}

			//find best one
			float bestWorkingTime = 0.0f;
			float bestTotalTime = 0.0f;

			std::for_each(bruteforceByNumOfConservators.at(numOfConservators - 1).begin(), 
				bruteforceByNumOfConservators.at(numOfConservators - 1).end(), 
				[&bestWorkingTime, &bestTotalTime](std::pair<SimulationResult, SimulationData> result) {
				if (result.first.workingTime > bestWorkingTime)
					bestWorkingTime = result.first.workingTime;
				if (result.first.totalTime > bestTotalTime)
					bestTotalTime = result.first.totalTime;
			});

			//create or modify rest
			for (uint i = 0; i < individuals; ++i)
			{
				if (bruteforceByNumOfConservators.at(numOfConservators - 1).at(i).first.workingTime != bestWorkingTime
					&& bruteforceByNumOfConservators.at(numOfConservators - 1).at(i).first.totalTime != bestTotalTime)
				{
					if (bruteforceByNumOfConservators.at(numOfConservators - 1).at(i).first.workingTime < bestWorkingTime / 2) //new individual
					{
						sdVector.at(i) = ++pg;
					}
					else { //modify individual (something like mutation)
						sdVector.at(i) = pm.modifyPermutation(sdVector.at(i));
					}
				}
			}
		}
		std::cout << "counter = " << counter << std::endl;

		sdVector.clear(); //clear individuals for another number of conservators
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
	std::cout << "Evolution(maxCost=" << maxCost << ", maxNumberOfConservators=" << maxNumberOfConservators << ", repets=" << repets << ", individuals=" << individuals << ", generations=" << generations << ")" << std::endl;
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
