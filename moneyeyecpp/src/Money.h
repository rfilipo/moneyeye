/**
 * Project eYe
 * @author Monsenhor
 * @version 0.001
 */


#ifndef _MONEY_H
#define _MONEY_H


#include <string>
#include "iModel.h"
using namespace std;

class Money: public iModel {
public: 
    
    /**
     * @param currency
     */
    void exchange(string currency);
private: 
    string currency;
    int value;
    string face;
    string country;
};

#endif //_MONEY_H
