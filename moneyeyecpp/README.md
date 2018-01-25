# MONEYeYe++

## NAME

MONEYeYe++

## VERSION

0.0.2

## SINOPSYS

```shell

moneyeye --help

  
```

## DESCRIPTION

Simple study for money and finance functions on TDD Method.

***

Version 0.0.2 - The object of the class Money must be small as possible and withouthard ties with large memory chunks, so all configurations and external resources as configurations, json files, lists, etc, must be done by a Prototype Factory Singleton class: MoneyFactory.

A money object must be instantiated like:

```c++

static MoneyFactory * fr = MoneyFactory::instance();
const Money * bill = fr->money("USD",700.00);

```

The Money prototype will have a pointer to the MoneyFactory instance, so all convertions and transformations with money will be made by the Factory.

Money must rewrite some arithmetic operators: = + - / * < > == and >> for exchange:

```c++

const Money invoice = bill; // clone bill

invoice = bill * 3; // clone bill and multiply value by 3

invoice >> "BRL";   // exchange to Real


```

### Steps
1. - Create a test module ( 002-FactoryTest.cpp ) to verify each requirement
	1. - Class existence and instantiation as Singleton
	2. - Constructor parameters: config_file, signs_file, rates_file
	3. - Class must get and set the parameters and controls to reload confs
	4. - Methods: exchange

2. Implement the class MoneyiFactory
	1. - class constructor, Singleton
	2. - Prototype to clone, getters and setters
	3. - Refactoring class Money to be thinny 
	

	***

Version 0.0.1 - Must have a class Money implementing the properties: value as integer, currency symbol, face value with currency symbol as String, country and the method Money::exchange("currency_symbol") returning a new Money object.

### Steps

1. - Create a test module ( 001-basicTest.cpp ) to verify each requirement
	1. - Class existence and instantiation
	2. - Class must be instantiated with the properties: currency, country, value
	3. - Class must get and set the properties value, currency and country
	4. - The method exchange must take the new value searching data from a local JSON file.

Download rates and signs from:
- https://www.currency-iso.org/dam/downloads/lists/list_one.xml
- http://fixer.io/
- https://docs.openexchangerates.org/docs/

2. Implement the class Money
	1. - class constructor
	2. - getters and setters
	3. - auxiliar method to read the JSON file returning only the data needed for this exchange
	4. - exchange method creating and returning a new Money object exchanged

## SEE ALSO

- autotools

https://en.wikipedia.org/wiki/GNU_Build_System

https://autotools.io/index.html

https://www.gnu.org/software/autoconf/autoconf.html

- Boost 

http://www.boost.org

http://www.boost.org/doc/libs/1_66_0/libs/test/doc/html/index.html

- Windows:

http://gnuwin32.sourceforge.net/packages/autoconf.htm
