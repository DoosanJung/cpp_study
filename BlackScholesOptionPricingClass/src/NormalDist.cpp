/*
 * NormalDist.cpp
 *
 *  Created on: Feb 27, 2018
 *      Author: doosanjung
 */

#define _USE_MATH_DEFINES
#include <cmath>
#include "../include/NormalDist.h"

inline double squared(double x)
{
	return x * x;
}

double normpdf(double x, double mu, double sigma)
{
	return (1.0/(sigma*sqrt(2.0*M_PI))) * exp(-0.5*squared(x - mu)/squared(sigma));
}

double normcdf(double x, double mu, double sigma)
{
	double v = (x - mu) / sigma;
	return 0.5 * erfc(-v * M_SQRT1_2);
}

