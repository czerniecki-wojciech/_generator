#include "RepairKit.h"

RepairKit::RepairKit()
    :backupParts(0)
{}

RepairKit::RepairKit(Element& element, std::shared_ptr<std::default_random_engine> defaultRandomEngine)
    :Element(element)
    ,backupParts(0)
    ,defaultRandomEngine(defaultRandomEngine)
{
    timeGenerator = std::make_shared<std::weibull_distribution<float>>(this->shape, this->scale);
}

RepairKit::RepairKit(const RepairKit& rk)
    :Element(rk)
{
    this->defaultRandomEngine = rk.defaultRandomEngine;
    this->timeGenerator = rk.timeGenerator;
	this->backupParts = rk.backupParts;
}

RepairKit& RepairKit::operator= (const RepairKit& rk)
{
    Element::operator =(rk);
    this->defaultRandomEngine = rk.defaultRandomEngine;
    this->timeGenerator = rk.timeGenerator;
	this->backupParts = rk.backupParts;

	return *this;
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

uint RepairKit::getNumberOfBackupsElemets()
{
    return backupParts;
}
