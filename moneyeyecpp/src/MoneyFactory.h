/**
 * Project moneyeye
 * @author Monsenhor
 * @version 0.01
 */

#ifndef _MONEYFACTORY_H
#define _MONEYFACTORY_H

#include <iostream>
#include <string>
#include <stdlib.h>
#include <cmath>
#include <cfenv>
#include <climits>
#include <unistd.h>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <chrono>
#include "lib/cJSON.c"

#include "Money.h"

using namespace std;

/**
 * Singleton, creates instances of money
 */
class MoneyFactory
{
  private:
		const string meyversion = "0.0.1";
		string root_dir   = "/etc/moneyeye";

  public:
		string version();
    static MoneyFactory *instance() {
			static MoneyFactory * mf = new MoneyFactory();
			return mf;
		}
		string getSign(string currency);

    Money * money();
    Money * money(string currency, string country, int value);
    Money * money(time_t time, string currency, int value);
    Money * exchange(Money * money, string currency);
  protected:
    MoneyFactory();
    MoneyFactory(string config);
};
#endif //_MONEYFACTORY_H
