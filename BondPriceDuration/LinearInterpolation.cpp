/*
 * LinearInterpolation.cpp
 *
 *  Created on: Feb 25, 2018
 *      Author: doosanjung
 */

double linearInterpolation(int matYears, int* curve_years, double* spot_rates) {

	double slope, spot;
	for (int i = 0; i < 9; i++) {
		if (matYears == curve_years[i])
			return spot_rates[i];
		else if (matYears > curve_years[i] && matYears < curve_years[i + 1]) {
			slope = (spot_rates[i + 1] - spot_rates[i]) / (curve_years[i + 1] - curve_years[i]);
			spot = spot_rates[i] + slope*(matYears - curve_years[i]);
			return spot;
		}
		else
			spot = 0;
			continue;
	}

}


