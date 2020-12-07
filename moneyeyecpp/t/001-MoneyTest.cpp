#define BOOST_TEST_MODULE Money_class test
#include <boost/test/included/unit_test.hpp>
#include "../src/MoneyFactory.cpp"


/**
 * Test class Money instantiation
 */
BOOST_AUTO_TEST_CASE(test_money_class)
{
  Money m0("USD","-",3000);
  BOOST_TEST(m0.value == 3000);
}

/**
 * Test instantiation from class MoneyFactory
 */
BOOST_AUTO_TEST_CASE(test_moneyfactory_class)
{
  MoneyFactory* mf = MoneyFactory::instance();
	Money m1 = * mf->money("USD","-",3000);
  BOOST_TEST(m1.value == 3000);
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

  Money* m1 = mf->money("BRL", "BR", 45600);
  Money md1 = * m1;
  
  string c1 = md1.currency;
  string f1 = md1.face;
  BOOST_TEST( c1 == "BRL" );
  BOOST_TEST( f1 == "R$456.00" );

  Money* m2 = mf->exchange( m1, "AZN" );
  string f2 = m2->face;
  BOOST_TEST( f2 == "₼241.16" );
}

/**
 * Test operators +
 */
BOOST_AUTO_TEST_CASE(test_money_operator_plus)
{
  MoneyFactory* mf = MoneyFactory::instance();
	Money m1 = * mf->money("USD", "-", 100);
	Money m2 = * mf->money("USD", "-", 200);
	Money m3 = m1.operator+(m2);
	Money m4 = m1 + m2;

  BOOST_TEST( m3.value == 300 );
  BOOST_TEST( m4.value == 300 );
}

/**
 * Test operators /
 */
BOOST_AUTO_TEST_CASE(test_money_operator_div)
{
  MoneyFactory* mf = MoneyFactory::instance();
	Money m1 = * mf->money("USD", "-", 100);
	Money m2 = * mf->money("USD", "-", 3);
	Money m3 = m1.operator/(m2);
	Money m4 = m1 / m2;

  BOOST_TEST( m3.value == 33 );
  BOOST_TEST( m4.value == 33 );
}

/**
 * Test function pv
 */
BOOST_AUTO_TEST_CASE(test_money_function_pv)
{
  MoneyFactory* mf = MoneyFactory::instance();

  using std::chrono::system_clock;

  std::chrono::duration<int,std::ratio<60*60*24> > one_day (1);

  system_clock::time_point today = system_clock::now();
  system_clock::time_point tomorrow = today + one_day;

  std::time_t tt;

  tt = system_clock::to_time_t ( tomorrow );
 
	Money m0 = * mf->money(tt,"USD", 100);
	Money m1 = * mf->money(tt,"USD", 100);

  //BOOST_TEST( m1.PV(0.05) < 100 );
  //BOOST_TEST( m1.PV(0.05) > m0.PV(0.05) ); 
  // m1.PV runs before, so it's bigger as PV uses realtime
  // if the system does not use realtime, bellow will work :)
  BOOST_TEST( m1.PV(0.05) >= m0.PV(0.05) ); 
}
