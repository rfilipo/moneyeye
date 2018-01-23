#define BOOST_TEST_MODULE MonEyeyeCpp test
#include <boost/test/included/unit_test.hpp>
//#include "../src/Money.h"
#include "../src/Money.cpp"

/**
 * Test class instantiation
 */
BOOST_AUTO_TEST_CASE(test_money_class)
{
  Money* m0 = new Money();
  BOOST_TEST(m0);
  Money* m1 = new Money("BRL", "BR", 12300);
  BOOST_TEST(m1); 
}

/**
 * Test setters and getters
 */
BOOST_AUTO_TEST_CASE(test_getters)
{
  Money* m0 = new Money();

  string c = m0->get_currency();
  string p = m0->get_country();
  int    v = m0->get_value();
  string f = m0->get_face()   ;

  BOOST_TEST( c == "USD" );
  BOOST_TEST( p == "US" );
  BOOST_TEST( v == 0 );
  BOOST_TEST( f == "US$0.00" );

  Money* m1 = new Money("BRL", "BR", 45600);

  string c1 = m1->get_currency();
  string f1 = m1->get_face();
  BOOST_TEST( c1 == "BRL" );
  BOOST_TEST( f1 == "R$456.00" );

  Money* m2 = m1->exchange("AZN");
  string f2 = m2->get_face();
  BOOST_TEST( f2 == "₼241.16" );
}

