/**
 * Project eYe
 * @author Monsenhor
 * @version 0.001
 */


#ifndef _BILLABLE_H
#define _BILLABLE_H

#include "iModel.h"


class Billable: public iModel {
public: 
    date date;
    date due;
    int value;
    string description;
    
    /**
     * @param value
     */
    bool receive(int value);
};

#endif //_BILLABLE_H