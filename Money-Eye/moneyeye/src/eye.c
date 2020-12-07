/**
    eye.c 
    moneyeye functions
    Copyright 2016 Monsenhor <filipo at kobkob.org>
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <config.h>
#include <time.h>
#include <eye.h>

#define LOGFILE "~/.moneyeye"

/**
 * @brief Creates a deposit and returns a transaction  
 *
 * Receives pointers to user, account and a double value
 * Modify account to have a new amount after deposit
 * Returns the transaction;
 */
transaction* deposit (double amount, transaction* deposit){
	 char l[256];
   sprintf(l, "Deposit: US$%.2f\n", amount);
   printf("Deposit: US$%.2f\n", amount);
   logme ( l );

   struct tm * timeinfo;
   time(&deposit->moment);
   timeinfo = localtime ( &deposit->moment );
   sprintf( l, "moment: %s\n", asctime(timeinfo));
   printf("moment: %s\n", asctime(timeinfo));
   logme( l );

   deposit->op      = 0;
   deposit->description = "Automatic deposit for budget calculation";
   deposit->ac->liquid += amount;
/*
   deposit->description = (char*) malloc((128) * sizeof(char));
   sprintf(deposit->description, 
       "Deposit of %2.4f in account %s by %s",
       amount, deposit->ac->name, deposit->user->name);
*/
   deposit->value = amount ;
   deposit->next = NULL;
   return deposit;
}
/**
 * @brief Creates a debit and returns a transaction  
 *
 * Receives pointer to transaction and a double value
 * Modify account to have a new amount after deposit
 * Returns the transaction;
 */
transaction* debit (double amount, transaction* debit){
	 char l[256];
   sprintf( l, "Debit: US$%.2f\n", amount);
   printf("Debit: US$%.2f\n", amount);
   logme ( l );

   struct tm * timeinfo;
   time(&debit->moment);
   timeinfo = localtime ( &debit->moment );
   sprintf( l, "moment: %s\n", asctime(timeinfo) );
   printf("moment: %s\n", asctime(timeinfo));
   logme ( l );

   debit->op      = 1;
   debit->description = "Automatic debit for budget calculation";
   debit->ad->liquid += amount;
/*
   debit->description = (char*) malloc((128) * sizeof(char));
   sprintf(debit->description, 
       "Deposit of %2.4f in account %s by %s",
       amount, debit->ac->name, debit->user->name);
*/
   debit->value = amount ;
   debit->next = NULL;
   return debit;
}


transaction* create_transaction(char* u, char* ac, char* ad){
     transaction* t =(transaction*)malloc(sizeof(transaction));
     account* a =(account*)malloc(sizeof(account));
     t->user = (user*)malloc(sizeof(user));
     t->user->name = u;
     t->ac = (account*)malloc(sizeof(account));
     t->ac->name = ac;
     t->ad = (account*)malloc(sizeof(account));
     t->ad->name = ad;
     t->moment = (time_t*)malloc(sizeof(time_t));
     time(&t->moment);
     // log stuff
     struct tm * timeinfo;
     timeinfo = localtime ( &t->moment ); 
     char l[256];
     strcpy(l, "Transaction created-");
     strcat(l, asctime(timeinfo));
     logme( l );
     logme( t->user->name );
     logme( t->ac->name );
     logme( t->ad->name );
     return t; 
}

void logme(char* m){
  printf("Log: %s\n", m);
  FILE * fp;
  fp = fopen ("moneyeye.log", "a+");
  //fp = fopen (LOGFILE, "a+");
  fprintf(fp, "%s\n", m);
  fclose (fp);
  //return 0; 
}

int trader (stock *s, double value, enum operation m){ return 0; }
double balance (char *period, user *u){return 0;}
int analyse (char *json){return 0;}


