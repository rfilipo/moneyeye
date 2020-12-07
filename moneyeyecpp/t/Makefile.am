ACLOCAL_AMFLAGS = -I m4
TESTS = factory_test money_test
check_PROGRAMS = factory_test money_test
factory_test_SOURCES = 000-FactoryTest.cpp ../src/Money.cpp 
money_test_SOURCES = 001-MoneyTest.cpp ../src/Money.cpp
money_test_FLAGS = --show_progress=yes
AM_CXXFLAGS = $(BOOST_CPPFLAGS) -std=c++11
#AM_CXXFLAGS = $(BOOST_CPPFLAGS) -std=c++11  -fprofile-arcs -ftest-coverage
