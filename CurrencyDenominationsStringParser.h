/*
 * CurrencyDenominationsStringParser.h
 *
 *  Created on: Jul 14, 2015
 *      Author: Chayne
 */

#ifndef CURRENCYDENOMINATIONSSTRINGPARSER_H_
#define CURRENCYDENOMINATIONSSTRINGPARSER_H_
#include <stdint.h>
#include <string>

class CurrencyDenominationsStringParser {
public:
	CurrencyDenominationsStringParser(std::string currencyAmount);
	~CurrencyDenominationsStringParser();
	int getDollars();
	int getCents();
private:
	int dollars;
	int cents;
};

#endif /* CURRENCYDENOMINATIONSSTRINGPARSER_H_ */
