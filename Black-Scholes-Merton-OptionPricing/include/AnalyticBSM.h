/*
 * AnalyticBS.h
 *
 *  Created on: Feb 26, 2018
 *      Author: doosanjung
 */

#ifndef INCLUDE_ANALYTICBSM_H_
#define INCLUDE_ANALYTICBSM_H_

#pragma once

#define MAX(x,y) (((x)>(y)) ? (x) : (y))

enum OptionType {Call=1,Put=-1};

double analytic_price(double s,
	double k,
	double r,
	double q,
	double t,
	double sigma,
	OptionType type);

#endif /* INCLUDE_ANALYTICBSM_H_ */
