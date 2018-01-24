# moneyeye

Simple study for money and finance functions on TDD Method.
  Tutorial for TDD development under autotools/cpp/boost

## Topics

- project methodologies and management (scrum, autotools, github)
- c++ revisions and libraries study (c++ core, boost, boost::test, cJSON)
- structural and model infra-structure (
- proof of concept about the work "Financial Numerical Recipes in C++" by Bernt Arne Ødegaard
http://finance.bi.no/~bernt/gcc_prog/recipes/recipes/recipes.html

### 1 - Requirements

Version 0.0.1 - Must have a class Money implementing the properties: value as integer, currency symbol, face value with currency symbol as String, country and the method Money::exchange("currency_symbol") returning a new Money object.

- Scrum guide
- Basic autotools project
- Create unit tests from requirements
- C++ Concepts ( Classes, Chars and Strings, 

Version 0.0.2 - The object of the class Money must be small as possible and without hard ties with large memory chunks, so all configurations and external resources as configurations, json files, lists, etc, must be done by a Prototype Factory Singleton class: MoneyFactory.

- D. Patterns: Factory, Singleton, Prototype, Pool 
- Refactoring 
- Overload operators
- Memory management

