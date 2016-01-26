#pragma once

#include <string>

#include "myTypes.h"

class CommandLineParser
{
public:
	bool BruteForce = false;
	bool Evolution = false;
	bool Adaptive = false;
	bool generatorInputFile = false;
	char* generatorInputFile_file;
	bool simulationInputFile = false;	
	char* simulationInputFile_file;
	uint repeats = 1;
	char outputFile = false;
	char* outputFile_file;

	CommandLineParser(int argc, char* argv[]);
};

