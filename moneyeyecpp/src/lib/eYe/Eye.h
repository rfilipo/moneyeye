/**
    Eye.h 
    moneye - manage money with command scripts. See docs for more info. 

    Copyright 2016 Monsenhor <filipo at kobkob.org>
 
    This file is part of moneye.

    moneye is free software: you can redistribute it and/or modify
    it under the terms of the GNU AFFERO GENERAL PUBLIC LICENSE as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    moneye is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU Affero General Public License
    along with moneye.  If not, see <http://www.gnu.org/licenses/>. 
 
*/

#ifndef _EYE_H
#define _EYE_H

#include <config.h>
#include <iostream>
#include <iomanip>
#include <ctime>
#include "Command.h"
#include "iModel.h"
#include "iView.h"


class Eye: public Command {
public: 
    iModel model;
    iView view;
    
    /**
     * @param value
     */
    bool pay(int value);
    
    /**
     * @param value
     */
    bool receive(int value);
    
    /**
     * @param data
     */
    bool task(std::string data);
    
    /**
     * @param begin
     * @param end
     */
    bool balance(std::time_t begin, std::time_t end);
    
    bool billable();
    
    bool payable();
};

#endif //_EYE_H


