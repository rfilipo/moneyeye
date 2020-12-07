/**
 * Project eYe
 * @author Monsenhor
 * @version 0.001
 */


#ifndef _REVENUE_H
#define _REVENUE_H

#include "iModel.h"


class Revenue: public iModel {
public: 
    date date;
    int value;
    string description;
};

#endif //_REVENUE_H