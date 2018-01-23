/**
 * Project eYe
 * @author Monsenhor
 * @version 0.001
 */


#ifndef _MONEY_H
#define _MONEY_H


#include <string>
#include <cmath>
#include <cfenv>
#include <climits>
#include <unistd.h>
#include <sstream>
#include <fstream>
#include <iostream>
#include <iomanip>
#include "lib/cJSON.c"

#include "iModel.h"

using namespace std;

class Money: public iModel {
public: 
    Money();
		Money(string currency, string country, int value);

    /**
		 * getters
		 */
    string get_currency();
    string get_country();
    int    get_value();
    string get_face();

    /**
     * @param currency
     */
    Money* exchange(string currency);

private: 
    string _currency;
    int    _value;
    string _face;
    string _country;

    cJSON * json_from ( const char * file );
};

#endif //_MONEY_H
