#ifndef SIMULATIONDATA_H
#define SIMULATIONDATA_H
#include <vector>
#include <iostream>
#include <algorithm> //for_each
#include "myTypes.h"
#include "Element.h"

class SimulationInputData {
private:

    friend std::ostream& operator<< (std::ostream& ostream, SimulationInputData* sd) {
        std::for_each(sd->elements.begin(), sd->elements.end(), [&ostream](Element& element) {
            ostream << element;
        });
        return ostream;
    }
protected:
    uint elementsNum;
    std::vector<Element> elements;

public:
    SimulationInputData(uint elementsNum)
        : elements(elementsNum)
    {}

    void erase() {
        elements.erase(elements.begin(), elements.end());
    }

    uint getElementsNum() {
        return elementsNum;
    }

    void setElement(Element element, uint elementIndex) {
        elements.insert(elements.begin() + elementIndex, 1, element);
    }

    void addElement(Element element) {
        elements.push_back(element);
    }

    void createAndAddNewElement(float shape, float scale, uint price) {
        elements.emplace_back(shape, scale, price);
    }
};

#endif // SIMULATIONDATA_H
