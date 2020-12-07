 /**
    budget.c
    moneyeye - manage money.
   
	  budget is a example implementation for the moneyeye library.

    budget receives a list of incomes and spendings returning 
    the resulting amount. It creates an unique transaction.
    
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
#include "eye.c"

void operate(int op, transaction* t);

int main() {
    int op; 
   // moneyeye needs username and account names to work
    transaction* t;
    char* username;
    char* acccred;
    char* accdebt;
    username = (char*) malloc((128) * sizeof(char));
    acccred  = (char*) malloc((128) * sizeof(char));
    accdebt  = (char*) malloc((128) * sizeof(char));
		printf ("Your username:\n");
    scanf("%s", username);
		printf ("Credit account:\n");
    scanf("%s", acccred);
		printf ("Debt account:\n");
    scanf("%s", accdebt);
    t = create_transaction(username, acccred, accdebt);
    printf("Transaction: budget for user %s from %s to %s \n", t->user->name, t->ac->name, t->ad->name);
    while ( op != 2){
		    printf ("0 - deposit,  1 - debit or 2 - end:\n");
        scanf("%d", &op); // it can be 0 - deposit,  1 - debit or 2 - end
        operate(op, t);
    }
    return 0;
}

void operate(int op, transaction* t){
    int n;
    double amount;
 
    switch (op) {
        case 0:
          printf("\n# Credit operation\n");
		      printf ("How many itens to deposit:\n");
          scanf("%d", &n); // number of itens
          for (int i = 0; i < n; i++) {
		          printf ("Amount %d:\nUS$", i+1);
              scanf("%lf", &amount);
              deposit(amount, t);
          }
          printf("Account %s earned US$%'.2lf\n",t->ac->name, t->ac->liquid);
          break;
        case 1:
          printf("\n# Debit operation\n");
		      printf ("How many itens to withdraw:\n");
          scanf("%d", &n); // number of itens
          for (int i = 0; i < n; i++) {
		          printf ("Amount %d:\nUS$", i+1);
              scanf("%lf", &amount);
              debit(amount, t);
          }
          printf("Account %s expent US$%'.2lf\n",t->ad->name, t->ad->liquid);
          break;
        case 2:
          printf("\nEnding!\n");
          printf("Liquid Credit US$%'.2lf\n", t->ac->liquid);
          printf("Liquid Debit  US$%'.2lf\n", t->ad->liquid);
          printf("Result        US$%'.2lf\n", t->ac->liquid - t->ad->liquid);
          break;
    }
}
