#include "SimulationInputDataGenerator.h"

SimulationInputDataGenerator::SimulationInputDataGenerator(char* filename)
{
	std::ifstream file(filename);

	if (file.is_open())
	{
		std::string garbage;

		uint maxCost;
		uint maxNumberOfConservators;
		float conservatorShapeMin;
		float conservatorShapeMax;
		float conservatorScaleMin;
		float conservatorScaleMax;
		uint numberOfElements;
		float elementShapeMin;
		float elementShapeMax;
		float elementScaleMin;
		float elementScaleMax;
		uint elementPriceMin;
		uint elementPriceMax;

		std::getline(file, garbage); // #max cost
		file >> maxCost;
		file >> garbage;
		std::getline(file, garbage); // #max number of conservators
		file >> maxNumberOfConservators;
		file >> garbage;
		std::getline(file, garbage); // #conservator weibull limits (shape_min, shape_max, scale_min, scale_max)
		file >> conservatorShapeMin;
		file >> conservatorShapeMax;
		file >> conservatorScaleMin;
		file >> conservatorScaleMax;
		file >> garbage;
		std::getline(file, garbage); // #number of elements
		file >> numberOfElements;
		file >> garbage;
		std::getline(file, garbage); // #elements weibull limits (shape_min, shape_max, scale_min, scale_max)
		file >> elementShapeMin;
		file >> elementShapeMax;
		file >> elementScaleMin;
		file >> elementScaleMax;
		file >> garbage;
		std::getline(file, garbage); // #element price limits
		file >> elementPriceMin;
		file >> elementPriceMax;

		file.close();


		this->elementsNum = numberOfElements;
		this->priceLimit = std::make_pair(elementPriceMin, elementPriceMax);
		this->outputsLimits = std::make_shared<OutputsLimits>(elementShapeMin, elementShapeMax, elementScaleMin, elementScaleMax);
		this->conservatorLimits = std::make_shared<ConservatorLimits>(conservatorShapeMin, conservatorShapeMax, conservatorScaleMin, conservatorScaleMax);
		this->maxCost = maxCost;
		this->maxNumberOfConservators = maxNumberOfConservators;
		std::srand(std::time(0));

	}
	else {
		std::cout << "Can't find file: " << filename << std::endl;
	}
}

SimulationInputDataGenerator::SimulationInputDataGenerator(uint elementsNum, std::shared_ptr<OutputsLimits> outputsLimits, std::pair<uint, uint> priceLimit, std::shared_ptr<ConservatorLimits> conservatorLimits, uint maxCost, uint maxNumberOfConservators)
{
    this->elementsNum = elementsNum;
    this->priceLimit = priceLimit;
    this->outputsLimits = outputsLimits;
    this->conservatorLimits = conservatorLimits;
	this->maxCost = maxCost;
	this->maxNumberOfConservators = maxNumberOfConservators;
    std::srand(std::time(0));
}

SimulationInputData SimulationInputDataGenerator::generate()
{
    SimulationInputData simulationData(this->elementsNum, this->maxCost, this->maxNumberOfConservators);
    simulationData.erase();

    float shape;
    float scale;
    int price;
	float min, max;

    for(uint i=0; i<this->elementsNum; ++i)
    {
		std::cout << (outputsLimits->shapeLimit.second - outputsLimits->shapeLimit.first) << std::endl;
		std::cout << (outputsLimits->shapeLimit.second - outputsLimits->shapeLimit.first) << std::endl;
		std::cout << int((outputsLimits->shapeLimit.second - outputsLimits->shapeLimit.first) * 10.0f) << std::endl;
		std::cout << static_cast<float>(rand() % int((outputsLimits->shapeLimit.second - outputsLimits->shapeLimit.first)) * 10.0f) << std::endl;
		std::cout << static_cast<float>(rand() % int((outputsLimits->scaleLimit.second - outputsLimits->scaleLimit.first)) * 10.0f) / outputsLimits->scaleLimit.second << std::endl;


		min = outputsLimits->shapeLimit.first;
		max = outputsLimits->shapeLimit.second;
		shape = rand() % int((max - min) * 10.0f) / 10.0f + min;

		min = outputsLimits->scaleLimit.first;
		max = outputsLimits->scaleLimit.second;
		scale = rand() % int((max - min) * 10.0f) / 10.0f + min;

        price = rand()%(priceLimit.second - priceLimit.first) + priceLimit.first;

        simulationData.createAndAddNewElement(shape, scale, price);
    }

	min = conservatorLimits->shapeLimit.first;
	max = conservatorLimits->shapeLimit.second;
	shape = rand() % int((max - min) * 10.0f) / 10.0f + min;

	min = conservatorLimits->scaleLimit.first;
	max = conservatorLimits->scaleLimit.second;
	scale = rand() % int((max - min) * 10.0f) / 10.0f + min;

    simulationData.addConservator(shape, scale);

    return simulationData;
}

