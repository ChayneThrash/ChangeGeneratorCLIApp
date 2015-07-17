/*
 * CurrencyDenominationsStringParser.cpp
 *
 *  Created on: Jul 14, 2015
 *      Author: Chayne
 */

#include "CurrencyDenominationsStringParser.h"
#include <iostream>
#include <ctype.h>

CurrencyDenominationsStringParser::CurrencyDenominationsStringParser(std::string currencyAmount)
{
	if (currencyAmount[0] != '$')
	{
		std::cout<<"Currency must begin with $."<<std::endl;
		exit(1);
	}
	std::string dollarsString("");
	std::string centsString("");
	bool periodDetected = false;
	int countAfterDecimal = 0;
	for (std::string::iterator iter = (currencyAmount.begin() + 1); iter != currencyAmount.end(); ++iter) // Begin parsing after the $
	{
		if (*iter == '.')
		{
			if (periodDetected)
			{
				std::cout<<"Currency can only have one decimal"<<std::endl;
				exit(1);
			}
			periodDetected = true;
			continue;
		}
		if (isdigit(*iter))
		{
			if (!periodDetected)
			{
				dollarsString += *iter;
			}
			else
			{
				if(++countAfterDecimal > 2)
				{
					std::cout<<"Currency must have only two numbers after the decimal."<<"\n";
					exit(1);
				}
				centsString += *iter;
			}
		}
		else
		{
			std::cout<<"The following invalid character was found: "<<*iter<<"\n";
			exit(1);
		}
	}
	dollars = std::stoi(dollarsString, 0);
	cents = std::stoi(centsString, 0);
}

CurrencyDenominationsStringParser::~CurrencyDenominationsStringParser()
{}

int CurrencyDenominationsStringParser::getDollars()
{
	return dollars;
}

int CurrencyDenominationsStringParser::getCents()
{
	return cents;
}
