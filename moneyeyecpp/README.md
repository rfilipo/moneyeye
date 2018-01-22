# MONEYeYe++

## NAME

MONEYeYe++

## VERSION

0.0.1

## SINOPSYS

```shell

moneyeye --help

  
```

## DESCRIPTION

Simple study for money and finance functions on TDD Method.

Version 0.0.1 - Must have a class Money implementing the properties: value as integer, currency symbol, face value with currency symbol as String, country and the method Money::exchange("currency_symbol") returning a new Money object.

### Steps

1 - Create a test module ( 001-basicTest.cpp ) to verify each requirement
1.1 - Class existence and instantiation
1.2 - Class must be instantiated with the properties: currency, country, value
1.3 - Class must get and set the properties value, currency and country
1.4 - The method exchange must take the new value searching data from a local JSON file.

Download it from:
- https://www.currency-iso.org/dam/downloads/lists/list_one.xml
- http://fixer.io/

2 - Implement the class Money so all tests PASS
2.1 - class constructor
2.2 - getters and setters
2.3 - auxiliar method to read the JSON file returning only the data needed for this exchange
2.4 - exchange method creating and returning a new Money object exchanged

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
