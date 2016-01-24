#include "CommandLineParser.h"

#include <iostream>

CommandLineParser::CommandLineParser(int argc, char * argv[])
{
	int currentInput = 0;
	while (currentInput < argc)
	{
		if (strcmp(argv[currentInput], "--BruteForce") == 0)
		{
			BruteForce = true;
		}
		else if (strcmp(argv[currentInput], "--Evolution") == 0)
		{
			Evolution = true;
		}
		else if (strcmp(argv[currentInput], "--Adaptive") == 0)
		{
			Adaptive = true;
		}
		else if (strcmp(argv[currentInput], "--generatorInputFile") == 0)
		{
			generatorInputFile = true;

			++currentInput;

			generatorInputFile_file = argv[currentInput];
		}
		else if (strcmp(argv[currentInput], "--simulationInputFile") == 0)
		{
			simulationInputFile = true;

			++currentInput;

			simulationInputFile_file = argv[currentInput];
		}
		else if (strcmp(argv[currentInput], "--repets") == 0)
		{
			++currentInput;

			repets = atoi(argv[currentInput]);
		}
		else if (strcmp(argv[currentInput], "--outputFile") == 0)
		{
			outputFile = true;

			++currentInput;

			outputFile_file = argv[currentInput];
		}

		++currentInput;
	}
}
