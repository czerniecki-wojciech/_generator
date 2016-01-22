#ifndef SIMULATIONINPUTDATA_H
#define SIMULATIONINPUTDATA_H
#include <vector>
#include <iostream>
#include <algorithm>
#include <memory>

#include "myTypes.h"
#include "Element.h"
#include "Conservator.h"

class SimulationInputData {
private:

    friend std::ostream& operator<< (std::ostream& ostream, SimulationInputData& sd) {
        std::for_each(sd.elements.begin(), sd.elements.end(), [&ostream](Element& element) {
            ostream << element;
        });
        return ostream;
    }
protected:
    uint elementsNum;
    std::vector<Element> elements;
    Conservator conservator;

public:
    SimulationInputData(uint elementsNum)
        :elementsNum(elementsNum)
    {}

    SimulationInputData(const SimulationInputData& sid)
        :elementsNum(sid.elementsNum)
        ,elements(sid.elements.size())
        ,conservator(sid.conservator)
    {
        std::copy(sid.elements.begin(), sid.elements.end(), this->elements.begin());
    }

    SimulationInputData& operator= (const SimulationInputData& sid)
    {
        this->elements = sid.elements;
        this->elementsNum = sid.elementsNum;
        this->conservator = sid.conservator;

        return *this;
    }

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

    void addConservator(float shape, float scale){
        conservator = Conservator(shape, scale);
    }
};

#endif // SIMULATIONINPUTDATA_H
