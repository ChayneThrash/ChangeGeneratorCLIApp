/*
 * CurrencyDenominations.cpp
 *
 *  Created on: Jul 13, 2015
 *      Author: Chayne
 */
#include <iostream>
#include <string>
#include "CurrencyDenominationsStringParser.h"
#include "OutputFormatter.h"

int generateDenomination(int denomination, int &val)
{
	int numDenominations = val/denomination;
	val -= numDenominations*denomination;
	return numDenominations;
}

int main()
{
	std::string userInput("");
	std::cout<<"Please enter a currency amount: ";
	std::cin>>userInput;

	CurrencyDenominationsStringParser parser(userInput);

	int dollars = parser.getDollars();
	int cents = parser.getCents();

	int numOfHundreds = generateDenomination(100, dollars);
	int numOfTwenties = generateDenomination(20, dollars);
	int numOfTens = generateDenomination(10, dollars);
	int numOfFives = generateDenomination(5, dollars);
	int numOfOnes = generateDenomination(1, dollars);

	int numOfQuarters = generateDenomination(25, cents);
	int numOfDimes = generateDenomination(10, cents);
	int numOfNickels = generateDenomination(5, cents);
	int numOfPennies = generateDenomination(1, cents);

	OutputFormatter formatter;
	formatter.addToOutput("$100: ", numOfHundreds).addToOutput("$20: ", numOfTwenties).addToOutput("$10: ", numOfTens)
			 .addToOutput("$5: ", numOfFives).addToOutput("$1: ", numOfOnes).addToOutput("Q: ", numOfQuarters)
			 .addToOutput("D: ", numOfDimes).addToOutput("N: ", numOfNickels).addToOutput("P: ", numOfPennies);

	std::cout<<formatter.getOutput();
}



