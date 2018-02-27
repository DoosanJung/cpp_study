/*
 * MonteCarloBS.h
 *
 *  Created on: Feb 26, 2018
 *      Author: doosanjung
 */

#ifndef INCLUDE_MONTECARLOBSM_H_
#define INCLUDE_MONTECARLOBSM_H_

#pragma once
#include "../include/AnalyticBSM.h"
#include "../include/PayOff.h"

double monte_carlo_price(double s,
	Payoff& payoff,
	double r,
	double q,
	double t,
	double sigma,
	unsigned int numOfSimulation);

#endif /* INCLUDE_MONTECARLOBSM_H_ */
