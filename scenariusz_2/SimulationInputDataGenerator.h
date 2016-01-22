#ifndef SIMULATIONDATAGENERATOR_H
#define SIMULATIONDATAGENERATOR_H

#include <ctime>
#include <cstdlib>
#include <memory>
#include <utility>

#include "myTypes.h"
#include "SimulationInputData.h"
#include "OutputsLimits.h"



class SimulationInputDataGenerator
{
private:
    uint elementsNum;
    std::pair<uint, uint> priceLimit;
    std::shared_ptr<OutputsLimits> outputsLimits;
    std::shared_ptr<ConservatorLimits> conservatorLimits;
public:
    //ctor
    SimulationInputDataGenerator(uint elementsNum, std::shared_ptr<OutputsLimits> outputsLimits, std::pair<uint, uint> priceLimit, std::shared_ptr<ConservatorLimits> conservatorLimits);

    //methods
    SimulationInputData generate();
};

#endif // SIMULATIONDATAGENERATOR_H