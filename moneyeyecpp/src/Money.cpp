/**
 * Project eYe
 * @author Monsenhor
 * @version 0.001
 */

#include "Money.h"
using namespace std;

/**
 * Money implementation
 * default to zero USD
 */
Money::Money () {
    _currency = "USD";
    _value    = 0;
    _face     = "US$0.00";
    _country  = "US";
}

/**
 * Money implementation
 *
 * Using custom currency. Search for symbol and generate a custom face
 *
 * @param string currency
 * @param string country
 * @param int value
 */
Money::Money (string currency, string country, int value) {
	  _currency = currency ;
    _country  = country  ;
    _value    = value    ;

    // set sign, default to currency code
    string sign_s = currency;

    cJSON * monitor_json = json_from ("/home/filipo/projetos/kobkob/code/moneyEye/rates/signs.json");
    const cJSON *item = NULL;
    cJSON_ArrayForEach(item, monitor_json)
    {
        const cJSON *code = cJSON_GetObjectItemCaseSensitive(item, "code");
        const cJSON *sign = cJSON_GetObjectItemCaseSensitive(item, "sign_utf8");
        if (currency.compare(0,2,code->valuestring,0,2) == 0) { 
            sign_s.assign(sign->valuestring); 
        }
    }
    cJSON_Delete(monitor_json);

    // TODO future function void set_face()
    ostringstream face_s;
    int value_u = value / 100;
    int value_c = value % 100;
    face_s << sign_s << value_u << "." << setfill('0') << setw(2) << value_c;
    _face     = face_s.str();       ;
}

/**
 * @param currency
 */
Money* Money::exchange(string currency) {
    cJSON * monitor_json = json_from ("/home/filipo/projetos/kobkob/code/moneyEye/rates/exchange_rate_0001.json");
    if (monitor_json == NULL)
    {
       const char *error_ptr = cJSON_GetErrorPtr();
       if (error_ptr != NULL)
       {
           cerr <<  "Error before: " <<  error_ptr << "\n";
       }
       return new Money();
    }

    const cJSON *rates = cJSON_GetObjectItemCaseSensitive(monitor_json, "rates");
    const cJSON *a_value = cJSON_GetObjectItemCaseSensitive(rates, _currency.c_str());
    const cJSON *x_value = cJSON_GetObjectItemCaseSensitive(rates, currency.c_str());
    if (!cJSON_IsNumber( a_value ) || !cJSON_IsNumber( x_value )) {
       cerr << "Error getting rates from JSON file. \n";
       return new Money();
    }
    cJSON_Delete(monitor_json);

    fesetround(FE_TONEAREST); // recomended rounding method for finance
                              // see https://en.wikipedia.org/wiki/Rounding
    int i_value = rint( _value * (x_value->valuedouble) / (a_value->valuedouble) );
     
    return new Money( currency, "--", i_value  );
}

/**
 *
 */
string Money::get_currency(){
    return _currency;	
}

/**
 *
 */
string Money::get_country(){
    return _country;	
}

/**
 *
 */
int Money::get_value(){
    return _value;	
}

/**
 *
 */
string Money::get_face(){
    return _face;	
}


cJSON * Money::json_from ( const char * file ) {
    ifstream t( file );

    if ( (t.rdstate() & ifstream::failbit ) != 0 ) {
       cerr << "Error opening signs file. \n";
    }

    ostringstream monitor;
    monitor << t.rdbuf();
    t.close(); 
    string monitor_s = monitor.str();
    const char * monitor_c = monitor_s.c_str();
    //cJSON *monitor_json = cJSON_Parse( monitor_c );
    return cJSON_Parse( monitor_c );
}

