/*
 * PayOff.h
 *
 *  Created on: Feb 26, 2018
 *      Author: doosanjung
 */

#pragma once
#ifndef INCLUDE_PAYOFF_H_
#define INCLUDE_PAYOFF_H_

#include "../include/AnalyticBSM.h"

class Payoff { //base class
public:
	virtual double getPayoff(double s) = 0; //a pure virtual function
};

class PlainVanillaPayoff : public Payoff {
public:
	PlainVanillaPayoff(double strike, OptionType type);
	virtual double getPayoff(double s);
protected:
	double strike_;
	OptionType type_;
};

class DigitalPayoff : public Payoff {
public:
	DigitalPayoff(double strike, OptionType type);
	virtual double getPayoff(double s);
protected:
	double strike_;
	OptionType type_;
};

#endif /* INCLUDE_PAYOFF_H_ */
