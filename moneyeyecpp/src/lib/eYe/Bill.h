/**
 * Project eYe
 * @author Monsenhor
 * @version 0.001
 */


#ifndef _BILL_H
#define _BILL_H

#include "iModel.h"


class Bill: public iModel {
public: 
    date date;
    int value;
    string description;
    bool paid;
};

#endif //_BILL_H