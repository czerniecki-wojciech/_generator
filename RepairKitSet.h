#ifndef REPAIRKITSET_H
#define REPAIRKITSET_H

#include <vector>
#include <random>
#include <algorithm>

#include "RepairKit.h"
#include "Element.h"

class RepairKitSet
{
private:
    std::vector<RepairKit> repairKits;
    friend std::ostream& operator<< (std::ostream& ostream, RepairKitSet* repairKidSet);
public:
    RepairKitSet(std::vector<Element> elements, std::shared_ptr<std::default_random_engine> defaultRandomEngine);

    uint getTotalElementsCost();
};

#endif // REPAIRKITSET_H
