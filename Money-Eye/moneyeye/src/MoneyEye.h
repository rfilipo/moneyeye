/**
    MoneyEye.h
    moneyeye header for data types
    Copyright 2016 Monsenhor <filipo at kobkob.org>

    moneyeye works on series of transactions defined  

*/

#ifndef _Eye_ctypes_H
#define _Eye_ctypes_H

#include <config.h>
#include <time.h>
#include <math.h>

enum role {
   User,
   Administrator,
   Trader,
   Guest
};

enum operation {
   Credit,
   Debit,
   Sell,
   Buy,
   Analyse
};

typedef struct {
   char *name;
   enum role status;
} user;

typedef struct {
   time_t moment;
   char *name;
   struct user *user;
   double liquid;
   double receivable;
   double due;
} account;

typedef struct {
   time_t moment;
   char *name;
   double value;
   double owned;
} stock;

typedef struct {
   time_t moment;
   struct user *seller;
   struct user *buyer;
   enum operation op;
   char *description;
   stock asset;
   double value;
} trade;

typedef struct{
   time_t moment;
   user* user;
   account* ac;
   account* ad;
   enum operation op;
   char* description;
   double value;
   struct transaction* next;
} transaction;

/* functions */
int trader (stock *s, double value, enum operation m);
transaction* deposit (double amount, transaction* t);
int debit (double amount, transaction* t);
double balance (char* period, user* u);
int analyse (char* json);
transaction* create_transaction(char* u, char* ac, char* ad);

#endif //_Eye_ctypes_H


