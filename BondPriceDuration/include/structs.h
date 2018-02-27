/*
 * structs.h
 *
 *  Created on: Feb 25, 2018
 *      Author: doosanjung
 */

#pragma once
#ifndef STRUCTS_H_
#define STRUCTS_H_

#include <string>
using namespace std;

struct PricingRst
{
	double dirtyprice;
	double NPV;
	double duration;

};

struct bondst
{
	string zcType;
	double faceValue, matYears, couponFreq, couponRate;
};

#endif /* STRUCTS_H_ */
