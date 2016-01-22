#ifndef PERMUTATIONITERATOR_H
#define PERMUTATIONITERATOR_H

#include "SimulationData.h"

class PermutationIterator
{
private:
    SimulationData simulationData;

    SimulationData nextPermutation();

    uint maxCost;
public:
    PermutationIterator(SimulationData& simulationData, uint maxCost);
    PermutationIterator(const PermutationIterator& pi);
    PermutationIterator& operator= (const PermutationIterator& pi);

    SimulationData get();
    void operator++();
};

#endif // PERMUTATIONITERATOR_H
