/**
 * Project eYe
 * @author Monsenhor
 * @version 0.001
 */


#ifndef _IVIEW_H
#define _IVIEW_H

#include "iModel.h"
#include "Eyeye.h"


class iView {
public: 
    iModel model;
    Eyeye eye;
    
    void show();
};

#endif //_IVIEW_H