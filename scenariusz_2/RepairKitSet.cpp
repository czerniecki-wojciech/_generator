#include "RepairKitSet.h"

RepairKitSet::RepairKitSet(std::vector<Element> elements, std::shared_ptr<std::default_random_engine> defaultRandomEngine)
{
    std::for_each(elements.begin(), elements.end(), [&](Element element)
	{
        repairKits.emplace_back(element, defaultRandomEngine);
    });
}

RepairKitSet::RepairKitSet(const RepairKitSet& rks)
    :repairKits(rks.repairKits.size())
{
    std::copy(rks.repairKits.begin(), rks.repairKits.end(), this->repairKits.begin());
}

RepairKitSet& RepairKitSet::operator=(const RepairKitSet& rks)
{
    this->repairKits = rks.repairKits;

	return *this;
}

std::ostream& operator<< (std::ostream& ostream, RepairKitSet& repairKidSet)
{
    std::for_each(repairKidSet.repairKits.begin(), repairKidSet.repairKits.end(), [&ostream](RepairKit& repairKit)
	{
        ostream << repairKit.getNumberOfBackupsElemets() << "(" << repairKit.getCostOfBackupElements() << ")|";
    });
    return ostream;
}

uint RepairKitSet::getElementsNum()
{
    return repairKits.size();
}

uint RepairKitSet::getTotalElementsCost() 
{
    uint totalCost = 0;

    std::for_each(repairKits.begin(), repairKits.end(), [&totalCost] (RepairKit repairKit)
	{
        totalCost += repairKit.getCostOfBackupElements();
    });

    return totalCost;
}

uint RepairKitSet::getNumberOfBackupsElemets(uint num)
{
    return repairKits.at(num).getNumberOfBackupsElemets();
}

float RepairKitSet::getDamageTime(uint num)
{
    return repairKits.at(num).getNextDamageTime();
}

bool RepairKitSet::isReplaceKitForElement(uint num) 
{
    return repairKits.at(num).getNumberOfBackupsElemets() > 0;
}

void RepairKitSet::takeReplaceKitForElement(uint num) 
{
    uint elements = repairKits.at(num).getNumberOfBackupsElemets();
    repairKits.at(num).setNumberOfBackupsElemets(elements -1);
}

void RepairKitSet::setNumOfReplaceKitForElement(uint num, uint elementsNum)
{
    repairKits.at(num).setNumberOfBackupsElemets(elementsNum);
}

uint RepairKitSet::getTotalCostOfElement(uint num)
{
    return repairKits.at(num).getCostOfBackupElements();
}
