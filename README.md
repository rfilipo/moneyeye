# moneyeye

## Features

1. Library Money::Eye in cpp
2. Note taking library in Perl/sqlite
2. Command line apps (facemoney, notemoney, timemoney, stckmoney, etc)
3. Qt Desktop app
3. Embedded C libraries
4. Embedded Node libraries 
2. Module Money::Eye in Perl
3. Command line app with Curses::UI
4. Mojolicious app (REST and Web app with Vuejs)
5. ReactNative app

# What is moneyeye?

Simple study for money and finance functions on TDD Method.
  Tutorial for TDD development under autotools/cpp/boost

The final system implement tools for creation and maintainance of asset records 
- debit or credit transactions
- several accounts
- several currencies
- authentication
- reporting
- data encryption
- payment transactions cicles
- documents/media files transactions cicles 
- financial Functions

## Topics

- project methodologies and management (scrum, autotools, github)
- c++ revisions and libraries study (c++ core, boost, boost::test, cJSON)
- structural and model infra-structure
- basic tests
- proof of concept about the work "Financial Numerical Recipes in C++" by Bernt Arne Ødegaard
http://finance.bi.no/~bernt/gcc_prog/recipes/recipes/recipes.html

## 1 - Requirements

__Version 0.1.?__ 

1. class Money implementing the properties: 
- value as integer, 
- currency symbol, 
- face value with currency symbol as String, 
- country and the 

2. And Methods: 
- Money::exchange("currency_symbol") returning a new Money object
- Money::

3. class Transaction with properties:
- date as String (UNIX timestamp)
- description as String
- value as integer
- debit account as String
- credit account as String

4. And Methods:
- Transaction::record()
- Transaction::delete(int id)
 
### Activities:
- Scrum guide
- Basic autotools project
- Create unit tests from requirements
- C++ Concepts ( Classes, Chars and Strings) 

__Version 0.2.?__ - The object of the class Money must be small as possible and without hard ties with large memory chunks, so all configurations and external resources as configurations, json files, lists, etc, must be done by a Prototype Factory Singleton class: MoneyFactory.

### Activities:
- D. Patterns: Factory, Singleton, Prototype, Pool 
- Refactoring 
- Overload operators
- Memory management

## 2 - Features

## 3 - Configuration

## 4 - Tests

## 5 - Release

