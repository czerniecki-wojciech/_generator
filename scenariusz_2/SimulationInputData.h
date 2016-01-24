#ifndef SIMULATIONINPUTDATA_H
#define SIMULATIONINPUTDATA_H
#include <vector>
#include <iostream>
#include <fstream>
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

	friend std::ofstream& operator<< (std::ofstream& ofstream, SimulationInputData& sd) {
		ofstream << "#max cost" << std::endl;
		ofstream << sd.maxCost << std::endl;
		ofstream << "#max number of conservators" << std::endl;
		ofstream << sd.maxNumberOfConservators << std::endl;
		ofstream << "#conservator weibull parameters (shape, scale)" << std::endl;
		ofstream << sd.conservator.getShape() << std::endl;
		ofstream << sd.conservator.getScale() << std::endl;
		ofstream << "#number of elements" << std::endl;
		ofstream << sd.elementsNum << std::endl;

		for (uint i = 0; i < sd.elementsNum; ++i)
		{
			ofstream << "#element " << i << " weibull parameters and price (shape, scale, price)" << std::endl;
			ofstream << sd.elements.at(i).getShape() << std::endl;
			ofstream << sd.elements.at(i).getScale() << std::endl;
			ofstream << sd.elements.at(i).getPrice() << std::endl;
		}

		return ofstream;
	}
protected:
    std::vector<Element> elements;
    Conservator conservator;

public:
    uint elementsNum;
	uint maxCost;
	uint maxNumberOfConservators;
	SimulationInputData(uint elementsNum, uint maxCost, uint maxNumberOfConservators)
		:elementsNum(elementsNum)
		, maxCost(maxCost)
		, maxNumberOfConservators(maxNumberOfConservators)
    {}

	SimulationInputData(const SimulationInputData& sid)
		:elementsNum(sid.elementsNum)
		, elements(sid.elements.size())
		, conservator(sid.conservator)
		, maxCost(sid.maxCost)
		, maxNumberOfConservators(sid.maxNumberOfConservators)
    {
        std::copy(sid.elements.begin(), sid.elements.end(), this->elements.begin());
    }

    SimulationInputData& operator= (const SimulationInputData& sid)
    {
        this->elements = sid.elements;
        this->elementsNum = sid.elementsNum;
        this->conservator = sid.conservator;
		this->maxCost = sid.maxCost;
		this->maxNumberOfConservators = sid.maxNumberOfConservators;

        return *this;
    }

	SimulationInputData(char* filename)
	{
		std::ifstream file(filename);
		std::string garbage;

		uint maxCost;
		uint maxNumberOfConservators;
		float conservatorShape;
		float conservatorScale;
		uint numberOfElements;
		float elementShape;
		float elementScale;
		uint elementPrice;

		std::getline(file, garbage); // #max cost
		file >> maxCost;
		file >> garbage;
		std::getline(file, garbage); // #max number of conservators
		file >> maxNumberOfConservators;
		file >> garbage;
		std::getline(file, garbage); // #conservator weibull parameters (shape, scale)
		file >> conservatorShape;
		file >> conservatorScale;
		file >> garbage;
		std::getline(file, garbage); // #number of elements
		file >> numberOfElements;

		this->elementsNum = numberOfElements;
		this->maxCost = maxCost;
		this->maxNumberOfConservators = maxNumberOfConservators;

		this->addConservator(conservatorShape, conservatorScale);

		for (uint i = 0; i < numberOfElements; ++i)
		{
			file >> garbage;
			std::getline(file, garbage); // #element X weibull parameters and price (shape, scale, price)
			file >> elementShape;
			file >> elementScale;
			file >> elementPrice;

			this->createAndAddNewElement(elementShape, elementScale, elementPrice);
		}

		file.close();
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
