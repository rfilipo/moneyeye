/**
 * Project moneyeye
 * @author Monsenhor
 * @version 0.01
 */


#ifndef _MONEY_H
#define _MONEY_H


#include <string>
#include <cmath>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cfenv>
#include <chrono>
/*
#include <climits>
#include <unistd.h>
#include <fstream>
*/

//#include "MoneyFactory.h"

using namespace std;
using chrono::high_resolution_clock;

class Money {
public: 
    Money();
		Money(string currency, string country, int value);
		Money(string currency, int value);
		Money(time_t time, string currency, int value);

    string currency;
    int    value;
    string face;
    string country;
    time_t  time;
    high_resolution_clock::time_point hr_time;
    string st_time;

    /**
     * @param currency
     */
    Money* exchange(string currency);

    /**
     * @param currency
     */
    double PV(double rate);


   /**
		* overload +
		*/
	 Money operator+ (const Money& m);
	 Money operator+ (const int t);

   /**
		* overload -
		*/
	 Money operator- (const Money& m);
	 Money operator- (const int t);

   /**
		* overload *
		*/
	 Money operator* (const Money& m);
	 Money operator* (const int t);

   /**
		* overload /
		*/
	 Money operator/ (const Money& m);

   /**
		* overload = for assigning integers
		*/
	 Money operator= (const int t);

   /**
		* overload += for assigning integers
		*/
	 Money operator+= (const int t);


private:
    //static MoneyFactory * factory;
};

#endif //_MONEY_H
