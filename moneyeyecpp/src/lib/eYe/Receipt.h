/**
 * Project eYe
 * @author Monsenhor
 * @version 0.001
 */


#ifndef _RECEIPT_H
#define _RECEIPT_H

#include "iModel.h"


class Receipt: public iModel {
public: 
    date date;
    int value;
    String description;
    bool paid;
};

#endif //_RECEIPT_H