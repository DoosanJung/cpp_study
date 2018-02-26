/*
 * main.cpp
 *
 *  Created on: Feb 25, 2018
 *      Author: doosanjung
 */

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>
#include "include/structs.h"
#include "include/LinearInterpolation.h"
#include "include/BondPricing.h"
using namespace std;

int main() {


		ifstream in("data/bond_input.csv");
		string str;
		vector<bondst> bond_input;
		while (in.good()) {

			getline(in, str);
			istringstream iss(str);
			string token;
			bondst tempbondZ;
			bondst tempbondC;
			getline(iss, token, ',');
			if (token == "Z") {
						tempbondZ.zcType = token;
						getline(iss, token, ',');
						tempbondZ.faceValue = stod(token);
						getline(iss, token, ',');
						tempbondZ.matYears = stod(token);
						bond_input.push_back(tempbondZ);
			}
			else if (token == "C") {
						tempbondC.zcType = token;
						getline(iss, token, ',');
						tempbondC.faceValue = stod(token);
						getline(iss, token, ',');
						tempbondC.matYears = stod(token);
						getline(iss, token, ',');
						tempbondC.couponFreq = stod(token);
						getline(iss, token, ',');
						tempbondC.couponRate = stod(token);
						bond_input.push_back(tempbondC);
			}
		}
		in.close();
		int inputSize = bond_input.size();

	//Calculating Bond price
	double n=10 ;
	double TotalNPV = 0, TotalDuration = 0, AvgDuration=0;

	int curve_years[10] = { 0,1,2,3,5,7,10,15,20,30 };
	double spot_rates[10] = { 1.5,1.5,1.6,1.8,2,2.2,2.5,2.7,2.8,2.9 };

	PricingRst* tmpBondPrice;
	cout << "No." << "\t" << "Type" << "\t" << "dirtyPrice" << "\t" << "NPV" << "\t" << "\t" << "Duration" << endl;
	cout << "==========================================================" << endl;
	for (int j = 0; j < inputSize; j++) {
		double faceValue = bond_input.at(j).faceValue;
		double matYears = bond_input.at(j).matYears;
		double freq = bond_input.at(j).couponFreq;
		double couponRate = bond_input.at(j).couponRate;
		try {
			if (bond_input.at(j).zcType == "Z") {
				tmpBondPrice=bond_pricing(n, curve_years, spot_rates, faceValue, matYears);
				double p_dirtyPrice = tmpBondPrice->dirtyprice;
				double p_NPV = tmpBondPrice->NPV;
				double p_duration = tmpBondPrice->duration;
				string zc;
				if (bond_input.at(j).zcType == "Z")
					zc = "ZC";
				cout <<j+1<<"\t"<< zc << "\t" << p_dirtyPrice << "\t" << "\t" << p_NPV << "\t" << "\t" << p_duration << endl;
				TotalNPV = TotalNPV + p_NPV;
				TotalDuration = TotalDuration + p_duration;
			}
			else{
				tmpBondPrice = bond_pricing(n, curve_years, spot_rates, faceValue, matYears, freq, couponRate);
				double p_dirtyPrice = tmpBondPrice->dirtyprice;
				double p_NPV = tmpBondPrice->NPV;
				double p_duration = tmpBondPrice->duration;
				cout << j + 1 << "\t" << bond_input.at(j).zcType << "\t" << p_dirtyPrice << "\t" << "\t" << p_NPV << "\t" << "\t" << p_duration << endl;
				TotalNPV = TotalNPV + p_NPV;
				TotalDuration = TotalDuration + p_duration;
			}
			AvgDuration = TotalDuration / inputSize;
		}
		catch (string e) {
			cout << e << endl;
		}
	}
	cout << "==========================================================" << endl;
	cout << "Aggregate" << "\t" << "\t" << "\t" << TotalNPV <<"\t"<< "\t" << AvgDuration << endl;
	return 0;
}


