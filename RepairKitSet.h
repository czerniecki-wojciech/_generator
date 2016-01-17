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
    RepairKitSet() = default;
    RepairKitSet(std::vector<Element> elements, std::shared_ptr<std::default_random_engine> defaultRandomEngine);
    RepairKitSet(const RepairKitSet& rks);
    RepairKitSet& operator=(const RepairKitSet& rks);

    uint getTotalElementsCost();
    uint getTotalCostOfElement(uint num);

    bool isReplaceKitForElement(uint num);
    void takeReplaceKitForElement(uint num);
    void setNumOfReplaceKitForElement(uint num, uint elementsNum);
};

#endif // REPAIRKITSET_H
