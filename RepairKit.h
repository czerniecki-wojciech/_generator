#ifndef REPAIRKIT_H
#define REPAIRKIT_H

#include <random>
#include <memory>

#include "Element.h"
#include "myTypes.h"

class RepairKit : public Element
{
private:
    uint backupParts;
    std::shared_ptr<std::default_random_engine> defaultRandomEngine;
    std::shared_ptr<std::weibull_distribution<float>> timeGenerator;
public:
    RepairKit(Element& element, std::shared_ptr<std::default_random_engine> defaultRandomEngine);
    RepairKit(const RepairKit& rk);
    RepairKit& operator= (const RepairKit&);

    uint getCostOfBackupElements();

    float getNextFailureTime();

    void setNumberOfBackupsElemets(uint number);
    uint getNumberOfBackupsElemets();
};

#endif // REPAIRKIT_H
