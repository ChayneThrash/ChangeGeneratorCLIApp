/*
 * OutputFormatter.h
 *
 *  Created on: Jul 16, 2015
 *      Author: Chayne
 */

#ifndef OUTPUTFORMATTER_H_
#define OUTPUTFORMATTER_H_
#include <string>

class OutputFormatter
{
public:
	OutputFormatter();
	~OutputFormatter();
	OutputFormatter& addToOutput(std::string format, int value);
	std::string getOutput();
private:
	bool beginningOfOutput;
	std::string formattedOutput;
};

#endif /* OUTPUTFORMATTER_H_ */
