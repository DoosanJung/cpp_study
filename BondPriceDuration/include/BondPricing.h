/*
 * BondPricing.h
 *
 *  Created on: Feb 25, 2018
 *      Author: doosanjung
 */

#pragma once
#ifndef BONDPRICING_H_
#define BONDPRICING_H_

#include <string>
#include <sstream>
#include "structs.h"
#include "LinearInterpolation.h"
#include <cmath>

PricingRst* bond_pricing(int n, int* curve_years, double* spot_rates, double faceValue, int matYears);
PricingRst* bond_pricing(int n, int* curve_years, double* spot_rates, double faceValue, int matYears, int freq, double couponRate);

#endif /* BONDPRICING_H_ */
