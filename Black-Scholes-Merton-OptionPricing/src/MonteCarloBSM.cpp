/*
 * MonteCarloBS.cpp
 *
 *  Created on: Feb 26, 2018
 *      Author: doosanjung
 */

#include <random>
#include "../include/MonteCarloBSM.h"

double monte_carlo_price(double s,
	Payoff& payoff,
	double r,
	double q,
	double t,
	double sigma,
	unsigned int numOfSimulation) {

	double sumOfPayoff = 0;
	double df = exp(-r*t);

	std::mt19937_64 prng; //	pseudo random number generator
	unsigned long sd = std::random_device{}();
	std::normal_distribution<double> engine(0.0, 1.0);
	prng.seed(sd);
	double es = s*exp((r - q - 0.5*sigma*sigma)*t);
	double diffution = sigma*sqrt(t);
	for (unsigned int i = 0; i < numOfSimulation; ++i) {
		double e = engine(prng);
		for (int j = 0; j < 2; ++j) {
			double st = es * exp(diffution*(1 - j * 2)*e);  //antithetic method
			double p = payoff.getPayoff(st);
			sumOfPayoff += df * p;
		}
	}
	return sumOfPayoff / numOfSimulation / 2.0;
}


