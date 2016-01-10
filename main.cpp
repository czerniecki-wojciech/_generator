#include <iostream>

#include "SimulationDataGenerator.h"

using namespace std;

int main()
{
    SimulationInputDataGenerator generator(10, std::make_pair<uint, uint>(0,10));
    std::shared_ptr<SimulationInputData> sd = generator.generate();

    cout << sd;

    cout << "Hello World!" << endl;
    return 0;
}

