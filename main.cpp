#include <iostream>

#include "SimulationInputDataGenerator.h"
#include "SimulationData.h"
#include "PermutationIterator.h"
#include "Simulation.h"

using namespace std;

int main()
{
    //generator
    std::pair<uint, uint> priceLimit = std::make_pair<uint, uint>(1, 10);
    std::pair<uint, uint> shapeLimit = std::make_pair<uint, uint>(1, 10);
    std::pair<uint, uint> scaleLimit = std::make_pair<uint, uint>(1, 10);

    std::shared_ptr<OutputsLimits> outputsLimits = std::make_shared<OutputsLimits>(shapeLimit, scaleLimit);
    std::shared_ptr<ConservatorLimits> conservatorLimits = std::make_shared<ConservatorLimits>(shapeLimit, scaleLimit);

    SimulationInputDataGenerator generator(3, outputsLimits, priceLimit, conservatorLimits);
    SimulationInputData simulationInputData = generator.generate();

    //simulator
    SimulationData simulationData(simulationInputData);

//    simulationData.setNumOfReplaceKitForElement(0 ,2);
//    simulationData.setNumOfReplaceKitForElement(1 ,3);

    cout << simulationInputData;
    cout << simulationData;

    uint maxCost = 20;
    uint maxNumberOfConservators = 2;
    uint reapets = 1;

    std::vector<std::vector<std::pair<SimulationResult, SimulationData>>> bruteforceByNumOfConservators;
    for(uint numOfConservators=1; numOfConservators<=maxNumberOfConservators; ++numOfConservators)
    {
        bruteforceByNumOfConservators.push_back(std::vector<std::pair<SimulationResult, SimulationData>>());
    }

    PermutationIterator pi(simulationData, maxCost);
    while(pi.get().getTotalElementsCost() <= maxCost)
    {
        for(uint numOfConservators=1; numOfConservators<=maxNumberOfConservators; ++numOfConservators)
        {
            Simulation simulation(pi.get(), maxCost - pi.get().getTotalElementsCost(), numOfConservators, reapets);
            std::cout << "sym for " << pi.get().getTotalElementsCost() << std::endl;
            std::cout << "avg result w " << simulation.getAvaragedResult().workingTime << std::endl;
            std::cout << "avg result t " << simulation.getAvaragedResult().totalTime << std::endl;
            bruteforceByNumOfConservators.at(numOfConservators-1)
                    .push_back(std::pair<SimulationResult, SimulationData>(simulation.getAvaragedResult(),
                                                                           pi.get()));
        }
        ++pi;
    }

    uint bestWorkingTime = 0;
    uint bestTotalTime = 0;
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

    std::cout << "Best working time: " << bruteforceByNumOfConservators.at(bestWorkingTimeNumOfConservators-1).at(indexBestWorkingTime).first.workingTime << std::endl;
    std::cout << "Numebr of conservators: " << bestWorkingTimeNumOfConservators << std::endl;
    std::cout << "SimulationData:" << std::endl;
    std::cout << bruteforceByNumOfConservators.at(bestWorkingTimeNumOfConservators-1).at(indexBestWorkingTime).second << std::endl;

    return 0;
}

