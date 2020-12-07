#define BOOST_TEST_MODULE MonEyeyeCpp factory test
#include <boost/test/included/unit_test.hpp>
#include "../src/MoneyFactory.cpp"


/**
 * Test class MoneyFactory instantiation
 */
BOOST_AUTO_TEST_CASE(test_moneyfactory_class)
{
  string mf = MoneyFactory::instance()->version();
  BOOST_TEST( mf == "0.0.1" );
}

/**
 * Test class MoneyFactory is a Singleton
 */
BOOST_AUTO_TEST_CASE(test_moneyfactory_singleton)
{
  MoneyFactory * mf1 = MoneyFactory::instance();
  MoneyFactory * mf2 = MoneyFactory::instance();
  BOOST_TEST( mf1 == mf2 );
}


/**
 * Test class Money instantiation
 */
BOOST_AUTO_TEST_CASE(test_money_class)
{
  MoneyFactory* mf = MoneyFactory::instance();
  Money* m0 = mf->money();
  BOOST_TEST(m0);
  Money* m1 = mf->money("BRL", "BR", 12300);
  BOOST_TEST(m1); 
}

/**
 * Test properties
 */
BOOST_AUTO_TEST_CASE(test_properties)
{
  MoneyFactory* mf = MoneyFactory::instance();
  Money* m0 = mf->money();

  string c = m0->currency;
  string p = m0->country;
  int    v = m0->value;
  string f = m0->face;

  BOOST_TEST( c == "USD" );
  BOOST_TEST( p == "US" );
  BOOST_TEST( v == 0 );
  BOOST_TEST( f == "US$0.00" );

  Money* m1 = mf->money("AZN", "--", 24116);

  string c1 = m1->currency;
  string f1 = m1->face;
  BOOST_TEST( c1 == "AZN" );
  BOOST_TEST( f1 == "₼241.16" );
}

/**
 * Test exchange
 */
BOOST_AUTO_TEST_CASE(test_exchange)
{
  MoneyFactory* mf = MoneyFactory::instance();
  Money* m1 = mf->money("BRL", "BR", 45600);
  Money* m2 = mf->exchange(m1, "AZN");
  string f2 = m2->face;
  BOOST_TEST( f2 == "₼241.16" );
}
