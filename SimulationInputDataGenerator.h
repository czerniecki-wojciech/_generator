#ifndef SIMULATIONDATAGENERATOR_H
#define SIMULATIONDATAGENERATOR_H
#include <ctime> //time
#include <cstdlib> //srand(), rand()
#include <memory> //shared_ptr, make_shared
#include "myTypes.h"
#include "SimulationData.h"

class SimulationInputDataGenerator
{
private:
    uint elementsNum;
    std::pair<uint, uint> costLimit;
public:
    //ctor
    SimulationInputDataGenerator(uint elementsNum, std::pair<uint, uint> costLimit);

    //methods
    std::shared_ptr<SimulationInputData> generate();
};

#endif // SIMULATIONDATAGENERATOR_H
