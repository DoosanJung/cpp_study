/*
 * main.cpp
 *
 *  Created on: Feb 26, 2018
 *      Author: doosanjung
 */

#include <iostream>
#include "../include/AnalyticBSM.h"
#include "../include/MonteCarloBSM.h"
#include "../include/PayOff.h"
#include "../include/BinomialBSM.h"

int main() {
	double s = 100, k = 100, r = 0.02, q = 0.01;
	double t = 91/365.0, sigma = 0.2;
	OptionType type = Put;

	// Analytic Price of Black-Scholes-Merton option pricing model
	double anal_price = analytic_price(s, k, r, q, t, sigma, type);
	std::cout << "Analytic B-S-M Price = " << anal_price << std::endl;
	std::cout << "===============================" << std::endl;

	PlainVanillaPayoff payoff(k, type);
	DigitalPayoff payoff1(k, type);

	// Monte-Carlo Simulation Price of Black-Scholes-Merton option pricing model
	unsigned int numOfSim = 1000000;
	double mc_price_pv = monte_carlo_price(s, payoff, r, q, t, sigma, numOfSim);
	double mc_price_di = monte_carlo_price(s, payoff1, r, q, t, sigma, numOfSim);
	std::cout << "Monte-Carlo B-S-M Price of Plain Vanilla payoff = " << mc_price_pv << std::endl;
	std::cout << "Monte-Carlo B-S-M Price of Digital payoff       = " << mc_price_di << std::endl;
	std::cout << "===========================================================" << std::endl;

	// Binomial Option Pricing Model Price of Black-Scholes-Merton option pricing model
	unsigned int nsteps = 300;
	double bnt_price_pv= binomial_price(s, payoff, r, q, t, sigma, nsteps);
	double bnt_price_di = binomial_price(s, payoff1, r, q, t, sigma, nsteps);
	std::cout << "Binomial B-S-M Price of Plain Vanilla payoff    = " << bnt_price_pv << std::endl;
	std::cout << "Binomial B-S-M Price of Digital payoff          = " << bnt_price_di << std::endl;
	std::cout << "===========================================================" << std::endl;

	// ..end
	return 0;
}



