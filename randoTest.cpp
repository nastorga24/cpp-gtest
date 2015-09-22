/**
 * Unit Tests for Rando Test
**/

#include <gtest/gtest.h>
#include "rando.h"

/*  
	FUNCTIONS WE NEED TO TEST:

	bool shouldWorry(bool,bool,bool);
	bool isDivisbleBy(int,int);
	bool isPrime(int);
	int nearestToZero(int,int);
*/
 
class RandoTest : public ::testing::Test
{
	protected:
		RandoTest(){} //constructor runs before each test
		virtual ~RandoTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

TEST(RandoTest, allChildrenSmile)
{
	Rando rando;
	ASSERT_TRUE( rando.shouldWorry(true,true,true) );
}

TEST(RandoTest, closestToZeroPositiveNumbers)
{
  Rando rando;
  ASSERT_TRUE( rando.nearestToZero(2,4) == 2);
  ASSERT_TRUE( rando.nearestToZero(4,2) == 2);
  ASSERT_TRUE( rando.nearestToZero(2,2) == 2);
}

TEST(RandoTest, closestToZeroNegativeNumbers)
{
  Rando rando;
  ASSERT_TRUE( rando.nearestToZero(-2,-4) == -2);
  ASSERT_TRUE( rando.nearestToZero(-4,-2) == -2);
  ASSERT_TRUE( rando.nearestToZero(-2,-2) == -2);
}

TEST(RandoTest, closestToZeroPositiveAndNegativeNumbers)
{
  Rando rando;
  ASSERT_TRUE( rando.nearestToZero(-2,4) == -2);
  ASSERT_TRUE( rando.nearestToZero(-4,2) == 2);
  ASSERT_TRUE( rando.nearestToZero(-2,2) == 2 || rando.nearestToZero(-2,2) == -2);
}

TEST(RandoTest, closestToZerosWithZeros)
{
  Rando rando;
  ASSERT_TRUE( rando.nearestToZero(2,0) == 2);
  ASSERT_TRUE( rando.nearestToZero(0,-2) == -2);
  ASSERT_TRUE( rando.nearestToZero(0,0) == 0);
}
