/*
 * BinomialBSM.h
 *
 *  Created on: Feb 26, 2018
 *      Author: doosanjung
 */

#pragma once
#ifndef INCLUDE_BINOMIALBSM_H_
#define INCLUDE_BINOMIALBSM_H_

#include "../include/AnalyticBSM.h"
#include "../include/PayOff.h"

double binomial_price(double s,
	Payoff& payoff,
	double r,
	double q,
	double t,
	double sigma,
	unsigned int nsteps);

#endif /* INCLUDE_BINOMIALBSM_H_ */
