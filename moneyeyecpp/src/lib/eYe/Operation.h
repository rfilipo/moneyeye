/**
 * Project eYe
 * @author Monsenhor
 * @version 0.001
 */


#ifndef _OPERATION_H
#define _OPERATION_H

#include "iModel.h"


class Operation: public iModel {
public: 
    date date;
    int value;
    string description;
};

#endif //_OPERATION_H