/*
 * LinearInterpolation.h
 *
 *  Created on: Feb 25, 2018
 *      Author: doosanjung
 */

#pragma once
#ifndef LINEARINTERPOLATION_H_
#define LINEARINTERPOLATION_H_

#include "structs.h"
#include <cmath>

double linearInterpolation(int matYears, int* curve_years, double* spot_rates);

#endif /* LINEARINTERPOLATION_H_ */
