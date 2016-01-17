#include "RepairKitSet.h"

RepairKitSet::RepairKitSet(std::vector<Element> elements, std::shared_ptr<std::default_random_engine> defaultRandomEngine)
{
    std::for_each(elements.begin(), elements.end(), [&](Element element) {
        repairKits.emplace_back(element, defaultRandomEngine);
    });
}

std::ostream& operator<< (std::ostream& ostream, RepairKitSet* repairKidSet) {
    std::for_each(repairKidSet->repairKits.begin(), repairKidSet->repairKits.end(), [&ostream](RepairKit& repairKit) {
        ostream << repairKit.getCostOfBackupElements() << "|";
    });
    return ostream;
}

uint RepairKitSet::getTotalElementsCost() {
    uint totalCost = 0;

    std::for_each(repairKits.begin(), repairKits.end(), [&totalCost] (RepairKit repairKit) {
        totalCost += repairKit.getCostOfBackupElements();
    });

    return totalCost;
}
