/**
 * Project moneyeye
 * @author Monsenhor
 * @version 0.0.1
 */

#include "Money.h"
using namespace std;

/**
 * Money implementation
 * default to zero USD
 */
Money::Money () {
    currency = "USD";
    value    = 0;
    face     = "US$0.00";
    country  = "US";
    using std::chrono::high_resolution_clock;
    high_resolution_clock::time_point t = high_resolution_clock::now();
    hr_time  = t;
    time_t tt = high_resolution_clock::to_time_t ( t );
    time     = tt;
    string st(ctime(&tt));
    st_time  = st; 
}

/**
 * Money implementation
 *
 * @param string currency
 * @param string country
 * @param int value
 */
Money::Money (string _currency, string _country, int _value) {
	  currency = _currency ;
    country  = _country  ;
    value    = _value    ;
    using std::chrono::high_resolution_clock;
    high_resolution_clock::time_point t = high_resolution_clock::now();
    time_t tt = high_resolution_clock::to_time_t ( t );

    hr_time  = t;
    time     = tt;
    string st(ctime(&tt));
    st_time  = st; 

    // set sign, default to currency code
    string sign_s = currency;
    ostringstream face_s;
    int value_u = value / 100;
    int value_c = value % 100;
    face_s << sign_s << value_u << "." << setfill('0') << setw(2) << value_c;
    face     = face_s.str();       ;
}

/**
 * Money implementation
 *
 * @param string currency
 * @param int value
 */
Money::Money (string _currency, int _value) {
    Money(_currency, "-", _value);
}
	
/**
 * Money implementation
 *
 * @param time_t time
 * @param string currency
 * @param int value
 */
Money::Money (time_t _time, string _currency, int _value) {
	  currency = _currency ;
    country  = "-"       ;
    value    = _value    ;
    time     = _time     ;

    // set sign, default to currency code
    string sign_s = currency;
    ostringstream face_s;
    int value_u = value / 100;
    int value_c = value % 100;
    face_s << sign_s << value_u << "." << setfill('0') << setw(2) << value_c;
    face     = face_s.str();       ;
}

/**
 *
 */

double Money::PV(double rate){
  using std::chrono::high_resolution_clock;
  high_resolution_clock::time_point t = high_resolution_clock::now();
  time_t tt = high_resolution_clock::to_time_t ( t );
  int month = 60*60*24*30; 
  double _PV = value * exp( -rate * ( time - tt ) / month );
  return _PV;
}

/**
 *
 */
Money Money::operator+ (const Money& m){
   cout << "Adding Moneys!!!";
   if (currency != m.currency){
      cerr << "Error: adding different currencies. \n";
			Money x;
			return x;
	 }
	 int new_value = value + m.value;
	 Money c(currency, country, new_value);
	 return c;
}

/**
 *
 */
Money Money::operator- (const Money& m){
   cout << "Adding Moneys!!!";
   if (currency != m.currency){
      cerr << "Error: adding different currencies. \n";
			Money x;
			return x;
	 }
	 int new_value = value - m.value;
	 Money c(currency, country, new_value);
	 return c;
}


/**
 *
 */
Money Money::operator* (const Money& m){
   cout << "Adding Moneys!!!";
   if (currency != m.currency){
      cerr << "Error: adding different currencies. \n";
			Money x;
			return x;
	 }
	 int new_value = value * m.value;
	 Money c(currency, country, new_value);
	 return c;
}


/**
 *
 */
Money Money::operator/ (const Money& m){
   cout << "Adding Moneys!!!";
   if (currency != m.currency){
      cerr << "Error: adding different currencies. \n";
			Money x;
			return x;
	 }

   fesetround(FE_TONEAREST); // recomended rounding method for finance
                              // see https://en.wikipedia.org/wiki/Rounding
   int new_value = rint( value / m.value );

	 Money c(currency, country, new_value);
	 return c;
}



/**
 *
 */
Money Money::operator= (const int t){
	 Money c(currency, country, t);
	 return c;
}

/**
 *
 */
Money Money::operator+= (const int t){
	 int new_value = value + t;
	 Money c(currency, country, new_value);
	 return c;
}



/**
 * @param currency
 */
Money* Money::exchange(string currency) {
    return new Money( currency, "--", 0  );
}


