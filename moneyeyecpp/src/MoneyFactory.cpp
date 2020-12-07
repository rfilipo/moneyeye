/**
 * Project moneyeye
 * @author Monsenhor
 * @version 0.01
 */

#include "MoneyFactory.h"
//#include "Money.h"

using namespace std;

string MoneyFactory::version (){
   return meyversion;	
}


/**
 * MoneyFactory implementation
 */
MoneyFactory::MoneyFactory () { }

/**
 * MoneyFactory implementation
 */
MoneyFactory::MoneyFactory (string config) { }



/**
 * Create default Money instance
 * default to zero USD
*/
Money* MoneyFactory::money () {
    Money  * _instance = new Money();
    return _instance;
}


/**
 * Create Money instance
 *
 * @param string currency
 * @param string country
 * @param int value
 */
Money* MoneyFactory::money (string currency, string country, int value) {

    string sign_s = getSign(currency);  // TODO!!!!

    ostringstream face_s;
    int value_u = value / 100;
    int value_c = value % 100;
    face_s << sign_s << value_u << "." << setfill('0') << setw(2) << value_c;
    Money * _money = new Money(currency, country, value);
    _money->face     = face_s.str();       
		return _money;
}

/**
 * Create Money instance
 *
 * @param time_t time
 * @param string currency
 * @param int value
 */
Money* MoneyFactory::money (time_t time, string currency, int value) {

    string sign_s = getSign(currency);  // TODO!!!!

    ostringstream face_s;
    int value_u = value / 100;
    int value_c = value % 100;
    face_s << sign_s << value_u << "." << setfill('0') << setw(2) << value_c;
    Money * _money = new Money(time, currency, value);
    _money->face     = face_s.str();       
		return _money;
}


/**
 * @param currency
 */
string MoneyFactory::getSign(string currency){
    // set sign, default to currency code
    string sign_s = currency;

    char* rPath;
    rPath = getenv ("MONEYEYE_ROOT");
    if (rPath!=NULL){
        string _root_dir(rPath);
        root_dir = _root_dir;
    }

    //string file = "/home/filipo/projetos/kobkob/code/moneyEye/rates/signs.json";
    string file = root_dir + "/rates/signs.json";
    ifstream t( file );

    if ( (t.rdstate() & ifstream::failbit ) != 0 ) {
       cerr << "Error opening signs file. \n";
    }

    ostringstream monitor;
    monitor << t.rdbuf();
    t.close(); 
    string monitor_s = monitor.str();
    const char * monitor_c = monitor_s.c_str();
    cJSON * monitor_json = cJSON_Parse( monitor_c );

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
    return sign_s;
}

/**
 * @param currency
 */
Money* MoneyFactory::exchange(Money * _money, string currency) {
	  int value = _money->value;

    //getRate(); //TODO!!!!!!
    string file = "/home/filipo/projetos/kobkob/code/moneyEye/rates/exchange_rate_0001.json";

    ifstream t( file );

    if ( (t.rdstate() & ifstream::failbit ) != 0 ) {
       cerr << "Error opening signs file. \n";
    }

    ostringstream monitor;
    monitor << t.rdbuf();
    t.close(); 
    string monitor_s = monitor.str();
    const char * monitor_c = monitor_s.c_str();
    cJSON * monitor_json = cJSON_Parse( monitor_c );

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
    const cJSON *a_value = cJSON_GetObjectItemCaseSensitive(rates, _money->currency.c_str());
    const cJSON *x_value = cJSON_GetObjectItemCaseSensitive(rates, currency.c_str());
    if (!cJSON_IsNumber( a_value ) || !cJSON_IsNumber( x_value )) {
       cerr << "Error getting rates from JSON file. \n";
       return new Money();
    }
    cJSON_Delete(monitor_json);

    fesetround(FE_TONEAREST); // recomended rounding method for finance
                              // see https://en.wikipedia.org/wiki/Rounding
    int i_value = rint( value * (x_value->valuedouble) / (a_value->valuedouble) );
     
    return money( currency, "--", i_value  );
}

/*
cJSON * MoneyFactory::json_from ( const char * file ) {
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
*/


