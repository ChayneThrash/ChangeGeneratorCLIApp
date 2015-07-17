/*
 * OutputFormatter.cpp
 *
 *  Created on: Jul 16, 2015
 *      Author: Chayne
 */

#include "OutputFormatter.h"

OutputFormatter::OutputFormatter() : beginningOfOutput(true), formattedOutput("")
{}

OutputFormatter::~OutputFormatter()
{}

OutputFormatter& OutputFormatter::addToOutput(std::string format, int value)
{
	if (value != 0)
	{
		if (!beginningOfOutput)
		{
			formattedOutput += ", ";
		}
		else
		{
			beginningOfOutput = false;
		}
		formattedOutput += format + std::to_string(value);
	}
	return *this;
}

std::string OutputFormatter::getOutput()
{
	return formattedOutput;
}
