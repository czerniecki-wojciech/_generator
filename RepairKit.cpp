#include "RepairKit.h"

RepairKit::RepairKit(Element& element, std::shared_ptr<std::default_random_engine> defaultRandomEngine)
    :Element(element)
    ,backupParts(0)
    ,defaultRandomEngine(defaultRandomEngine)
{
    timeGenerator = std::make_shared<std::weibull_distribution<float>>(this->shape, this->scale);
}

uint RepairKit::getCostOfBackupElements()
{
    return price * backupParts;
}


float RepairKit::getNextFailureTime()
{
    return timeGenerator->operator ()(*(defaultRandomEngine));
}

void RepairKit::setNumberOfBackupsElemets(uint number)
{
    this->backupParts = number;
}
