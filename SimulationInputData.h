#ifndef SIMULATIONINPUTDATA_H
#define SIMULATIONINPUTDATA_H
#include <vector>
#include <iostream>
#include <algorithm>
#include <memory>

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
        :elementsNum(elementsNum)
    {}

    //SimulationInputData() = default;

    SimulationInputData(const SimulationInputData& sid)
        :elementsNum(sid.elementsNum)
        ,elements(sid.elements.size())
    {
        std::copy(sid.elements.begin(), sid.elements.end(), this->elements.begin());
        std::cout << "A" << this->elements.size();
        std::cout << "Asid" << sid.elements.size();
    }

    SimulationInputData& operator= (const SimulationInputData& sid)
    {
        this->elements = sid.elements;
        this->elementsNum = sid.elementsNum;
        std::cout << "B";

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
};

#endif // SIMULATIONINPUTDATA_H
