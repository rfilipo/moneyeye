/**
 * Project eYe
 * @author Monsenhor
 * @version 0.001
 */


#ifndef _PAYMENT_H
#define _PAYMENT_H

#include "iModel.h"


class Payment: public iModel {
public: 
    date date;
    int value;
    string description;
};

#endif //_PAYMENT_H