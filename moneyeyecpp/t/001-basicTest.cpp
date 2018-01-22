#define BOOST_TEST_MODULE MonEyeyeCpp test
#include <boost/test/included/unit_test.hpp>
#include "../src/Money.h"


BOOST_AUTO_TEST_CASE(test_money_class)
{
  Money* m = new Money();
  BOOST_TEST(m); 
}

