/*
 * BondPricing.cpp
 *
 *  Created on: Feb 25, 2018
 *      Author: doosanjung
 */


#include "../include/structs.h"
#include "../include/LinearInterpolation.h"

PricingRst* bond_pricing(int n, int* curve_years, double* spot_rates, double faceValue, int matYears) {
	if (matYears > 30)
		throw(string("Error:THe maturity should be less than 30 years."));
	PricingRst zeroCouponBond;
	for (int i = 1; i <= matYears; i++) {
		if (matYears == i){
			double spot = linearInterpolation(i, curve_years, spot_rates);
			double spotPercent = spot / 100;
			zeroCouponBond.NPV = faceValue * exp(-spotPercent * i);
			zeroCouponBond.dirtyprice = 100 * exp(-spotPercent  * i);
			zeroCouponBond.duration = i;
			break;
		}
	}
	return &zeroCouponBond;
}

PricingRst* bond_pricing(int n, int* curve_years, double* spot_rates, double faceValue, int matYears,int freq, double couponRate){
	if (matYears > 30)
		throw(string("Error:THe maturity should be less than 30 years."));
	PricingRst couponBond;
	double sum_NPV = 0, sum_Price = 0, sum_Duration = 0, spotPercent = 0;
	double coupon_Price = (100 * (couponRate / 100)) / freq;
	double coupon_NPV = (faceValue * (couponRate / 100)) / freq;
	double calculationYear = 0;
	for (int i = 1; i <= matYears; i++){
		for (int j = 1; j <= freq; j++){
			double spot = linearInterpolation(i, curve_years, spot_rates);
			spotPercent = spot / 100;
			calculationYear++;
			sum_Price = sum_Price + coupon_Price * exp(-spotPercent * (calculationYear / freq));
			sum_NPV = sum_NPV + coupon_NPV * exp(-spotPercent * (calculationYear / freq));
			sum_Duration = sum_Duration + (calculationYear / freq) * coupon_NPV*exp(-spotPercent * (calculationYear / freq));
		}
	}

	sum_Price = sum_Price + 100 * exp(-spotPercent * matYears);
	sum_NPV = sum_NPV + faceValue * exp(-spotPercent * matYears);
	sum_Duration = sum_Duration + (calculationYear / freq) * faceValue * exp(-spotPercent * matYears);

	// return
	couponBond.dirtyprice = sum_Price;
	couponBond.NPV = sum_NPV;
	couponBond.duration = sum_Duration / sum_NPV;
	return &couponBond;
}


