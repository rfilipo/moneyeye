 /**
    main.c
    moneyeye - manage money with command scripts.
    See docs for more info.

    Copyright 2016 Monsenhor <filipo at kobkob.org>

    This file is part of moneyeye.

    moneyeye is free software: you can redistribute it and/or modify
    it under the terms of the GNU AFFERO GENERAL PUBLIC LICENSE as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    moneyeye is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU Affero General Public License
    along with moneyeye.  If not, see <http://www.gnu.org/licenses/>.

*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include "eye.h"

void operate(int op, transaction* t);

int main() {
    int op; 
    transaction* t;
    // moneyeye needs username and account names to work
    char* username;
    char* acccred;
    char* accdebt;
    username = (char*) malloc((128) * sizeof(char));
    acccred  = (char*) malloc((128) * sizeof(char));
    accdebt  = (char*) malloc((128) * sizeof(char));
    while ( op != 5){
        scanf("%d", &op); 
        operate(op, t);
    }
    return 0;
}



void operate(int op, transaction* t){
    int n;
    double amount;
 
    //scanf("%s", username);
    //scanf("%s", acccred);
    //scanf("%s", accdebt);
    switch (op) {
        case 0:
          printf("deposit\n");
          //printf("Account have %'.2lf\n", ac.liquid);
          break;
        case 1:
          printf("debit\n");
          //printf("Account have %'.2lf\n", amount - value);
          break;
        case 2:
          printf("buy\n");
          //printf("Account have %'.2lf\n", amount - value);
          break;
        case 3:
          printf("sell\n");
          //printf("Account have %'.2lf\n", amount + value);
          break;
        case 4:
          printf("balance\n");
          //printf("Account have %'.2lf\n", amount + value);
          break;
    }
}


