/*
 * Date.h
 *
 *  Created on: Feb 27, 2018
 *      Author: doosanjung
 */

#pragma once
#ifndef INCLUDE_DATE_H_
#define INCLUDE_DATE_H_

class Date
{
public:
	Date(unsigned int year, unsigned int month, unsigned int day)
		: year_(year), month_(month), day_(day) {};
	~Date() {};
	unsigned int year() { return year_; }
	unsigned int month() { return month_; }
	unsigned int day() { return day_; }
private:
	unsigned int year_, month_, day_;
};

int daysBetween(Date d1, Date d2);

#endif /* INCLUDE_DATE_H_ */
