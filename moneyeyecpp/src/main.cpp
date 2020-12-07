 /**
    main.cpp
    MonEyeyeCpp - simple cpp skeleton.

    Copyright 2016 Monsenhor <filipo at kobkob.org>

    This file is part of MonEyeyeCpp.

    MonEyeyeCpp is free software: you can redistribute it and/or modify
    it under the terms of the GNU AFFERO GENERAL PUBLIC LICENSE as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    MonEyeyeCpp is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU Affero General Public License
    along with MonEyeyeCpp.  If not, see <http://www.gnu.org/licenses/>.

*/

#include <unistd.h>
//#include <config.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <sstream>
#include <ctype.h>

#include "./src/MoneyFactory.cpp"

#ifndef VERSION
#define VERSION 0.01
#endif

using namespace std;

void printUsage (char *ar) {
   fprintf(stderr, "Usage: %s [-d] \"description frase\" [-r \"XXX,XXX.XX\"] || [-p \"XXX,XXX.XX\" ] || [-t file]\n", ar);
}

/**
 * MonEyeyeCpp
 */
int main(int argc, char* argv[]) {
    cout << "moneyeye++ " << VERSION << " - Copyleft GPL 3.0 by Monsenhor" << "\n\n";

    const char * currency = "USD";
    const char * country  = "US";
    const char * currency_to = "EUR";
    const char * value;
    ostringstream monitor;

    int c; 
    while ((c = getopt (argc, argv, "c:v:u:t:")) != -1)
    switch (c)
      {
      case 'c':
        currency = optarg;
        monitor << "From: " << currency;
        break;
      case 'v':
        value = optarg;
        monitor << " " << value;
        break;
      case 'u':
        country = optarg;
        break;
      case 't':
        currency_to = optarg;
        monitor << " To: " << currency_to;
        break;
      case '?':
        cout << "implement me!!!" << "\n";
        return 1;
      default:
        abort ();
     }

     //printf ("currency = %s, value = %s, to = %s\n",
     //     currency, value, currency_to);

     string s_currency(currency);
     string s_country(country);
     string s_currency_to(currency_to);
     MoneyFactory * mf = MoneyFactory::instance();
     Money * m0 = mf->money( s_currency, s_country, atoi(value));
     Money * m1 = mf->exchange( m0, s_currency_to);

     cout << m1->face << "\n";
     
     //cout << monitor.str() << "\n";
     //cout << "Done!\n";

     exit(EXIT_SUCCESS);
}


