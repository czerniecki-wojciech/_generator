#include <iostream>

#include "SimulationInputDataGenerator.h"
#include "SimulationData.h"
#include "PermutationIterator.h"
#include "Simulation.h"
#include "BruteForce.h"
#include "Evolution.h"
#include "EvolutionHelper.h"
#include "Adaptive.h"
#include "CommandLineParser.h"

using namespace std;

int main(int argc, char* argv[])
{
	CommandLineParser clp(argc, argv);

	if (clp.generatorInputFile && clp.outputFile) 
	{
		SimulationInputDataGenerator generator(clp.generatorInputFile_file);
		SimulationInputData simulationInputData2 = generator.generate();

		ofstream file(clp.outputFile_file);

		file << simulationInputData2;
		file.close();
	}
	else if (clp.simulationInputFile && (clp.Adaptive || clp.BruteForce || clp.Evolution)) {
		SimulationInputData simulationInputData(clp.simulationInputFile_file);

		std::cout << "Starting siulation for:" << std::endl;
		std::cout << simulationInputData << std::endl << std::endl;

		SimulationData simulationData(simulationInputData);

		if (clp.Adaptive) 
		{
			Adaptive ad(simulationData, simulationInputData.maxCost, simulationInputData.maxNumberOfConservators, clp.repeats);
		}
		if (clp.BruteForce) 
		{
			BruteForce bf(simulationData, simulationInputData.maxCost, simulationInputData.maxNumberOfConservators, clp.repeats);
		}
		if (clp.Evolution) 
		{
			EvolutionHelper eh(simulationInputData.maxCost, simulationData);

			uint numOfIndividuals = eh.getIndividualsNum();
			uint numOfGenerations = eh.getGenerationNum();
			Evolution ev(simulationData, simulationInputData.maxCost, simulationInputData.maxNumberOfConservators, clp.repeats, numOfIndividuals, numOfGenerations);
		}
	}
	else {
        std::cout << "Example use:" << std::endl;
        std::cout << "./_generator --generatorInputFile generator_input.txt --outputFile simulation_input.txt" << std::endl << "^ generates simulation input file from generator_input.txt" << std::endl;
        std::cout << "./_generator --simulationInputFile simulation_input.txt --BruteForce --Evolution --Adaptive --repeats 100" << std::endl << "^ starts simulation with all three algorithms on sinulation_indput.txt simulation data with repeats set to 1000" << std::endl;

        std::cout << std::endl << "Example generator_input.txt:" << std::endl;
		std::cout << "#max cost" << std::endl;
		std::cout << "50" << std::endl;
		std::cout << "#max number of conservators" << std::endl;
		std::cout << "3" << std::endl;
        std::cout << "#conservator weibull limits(shape_min, shape_max, scale_min, scale_max) accepts floats" << std::endl;
		std::cout << "1" << std::endl;
		std::cout << "10" << std::endl;
		std::cout << "1" << std::endl;
		std::cout << "10" << std::endl;
		std::cout << "#number of elements" << std::endl;
		std::cout << "4" << std::endl;
        std::cout << "#elements weibull limits(shape_min, shape_max, scale_min, scale_max) accepts floats" << std::endl;
		std::cout << "1" << std::endl;
		std::cout << "10" << std::endl;
		std::cout << "1" << std::endl;
		std::cout << "10" << std::endl;
        std::cout << "#element price limits, only integer values" << std::endl;
		std::cout << "1" << std::endl;
		std::cout << "10" << std::endl;
	}

    return 0;
}

