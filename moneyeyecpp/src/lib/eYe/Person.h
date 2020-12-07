/**
 * Project eYe
 * @author Monsenhor
 * @version 0.001
 */


#ifndef _PERSON_H
#define _PERSON_H

#include "iModel.h"


class Person: public iModel {
public: 
    string name;
    string email;
    string document;
    string phone;
};

#endif //_PERSON_H