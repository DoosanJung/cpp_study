/*
 * main.cpp
 *
 *  Created on: Feb 27, 2018
 *      Author: doosanjung
 */

#include <iostream>
#include <ctime>
#include <chrono>
#include "../include/Date.h"
#include "../include/PlainVanillaOption.h"

int main() {
	// checking time
	using namespace std::chrono;
	high_resolution_clock::time_point t1 = high_resolution_clock::now();

	Date evalDate(2018, 1, 1); //evaluation date
	Date mat(2018, 2, 28); //maturity date
	double spot = 100, stk = 100, rf = 0.01, div = 0.01, vol = 0.2;
	OptionType type = Call;
	PlainVanillaOption pv_option(mat, stk, type);
	GBMProcess gbm_process(spot, rf, div, vol);
	pv_option.setProcess(gbm_process);

	std::cout << "price = " << pv_option.price(evalDate) << std::endl;
	std::cout << "vega = " << pv_option.vega(evalDate) << std::endl;
	double mktPrice = 3.1;
	std::cout << "implied vol = " << pv_option.impliedVol(evalDate, mktPrice) << std::endl;

	// checking time
	high_resolution_clock::time_point t2 = high_resolution_clock::now();
	duration<double> time_span = duration_cast<duration<double>>(t2 - t1);
	std::cout << "It took me " << time_span.count() << " seconds.";
	return 0;
}



