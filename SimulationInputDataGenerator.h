#ifndef SIMULATIONDATAGENERATOR_H
#define SIMULATIONDATAGENERATOR_H

#include <ctime>
#include <cstdlib>
#include <memory>
#include <utility>

#include "myTypes.h"
#include "SimulationData.h"
#include "OutputsLimits.h"



class SimulationInputDataGenerator
{
private:
    uint elementsNum;
    std::pair<uint, uint> priceLimit;
public:
    //ctor
    SimulationInputDataGenerator(uint elementsNum, OutputsLimits& OutputsLimits, std::pair<uint, uint> priceLimit);

    //methods
    std::shared_ptr<SimulationInputData> generate();
};

#endif // SIMULATIONDATAGENERATOR_H
