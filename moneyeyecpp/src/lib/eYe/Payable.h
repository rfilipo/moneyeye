/**
 * Project eYe
 * @author Monsenhor
 * @version 0.001
 */


#ifndef _PAYABLE_H
#define _PAYABLE_H

#include "iModel.h"


class Payable: public iModel {
public: 
    date date;
    date due;
    int value;
    string description;
    
    /**
     * @param value
     */
    bool pay(int value);
};

#endif //_PAYABLE_H