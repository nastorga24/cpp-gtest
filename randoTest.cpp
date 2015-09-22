/**
 * Unit Tests for Rando Test
**/
//Natalie Astorga
// 09/22/15
// CSCI 430

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

TEST(RandoTest, OneChildrenSmile)
{
	Rando rando;
	ASSERT_TRUE( rando.shouldWorry(true,false,false) );
	ASSERT_TRUE( rando.shouldWorry(false,true,false) );
	ASSERT_TRUE( rando.shouldWorry(false,false,true) );
}

TEST(RandoTest, twoChildrenSmile)
{
	Rando rando;
	ASSERT_FALSE( rando.shouldWorry(true,true,false) );
	ASSERT_FALSE( rando.shouldWorry(true,false,true) );
	ASSERT_FALSE( rando.shouldWorry(false,true,true) );
}

TEST(RandoTest, PositivePrimes)
{
  Rando rando;
  ASSERT_TRUE( rando.isPrime(1));
  ASSERT_TRUE( rando.isPrime(7));
  ASSERT_TRUE( rando.isPrime(611953));
}

TEST(RandoTest, NegativePrimes)
{
  Rando rando;
  ASSERT_TRUE( rando.isPrime(-1));
  ASSERT_TRUE( rando.isPrime(-7));
  ASSERT_TRUE( rando.isPrime(-611953));
}

TEST(RandoTest, PositiveComposite)
{
  Rando rando;
  ASSERT_FALSE( rando.isPrime(4));
  ASSERT_FALSE( rando.isPrime(8));
  ASSERT_FALSE( rando.isPrime(611954));
}

TEST(RandoTest, NegativeComposite)
{
  Rando rando;
  ASSERT_FALSE( rando.isPrime(-4));
  ASSERT_FALSE( rando.isPrime(-8));
  ASSERT_FALSE( rando.isPrime(-611954));
}

TEST(RandoTest, ZeroPrime)
{
  Rando rando;
  ASSERT_FALSE( rando.isPrime(0));
}

TEST(RandoTest, DivisbleByPositiveNumbers)
{
  Rando rando;
  ASSERT_TRUE( rando.isDivisbleBy(2,4));
  ASSERT_TRUE( rando.isDivisbleBy(4,2));
  ASSERT_FALSE( rando.isDivisbleBy(3,5));
  ASSERT_FALSE( rando.isDivisbleBy(5,3));
}

TEST(RandoTest, DivisbleByZeroNumbers)
{
  Rando rando;
  ASSERT_TRUE( rando.isDivisbleBy(3,0));
  ASSERT_TRUE( rando.isDivisbleBy(3,0));
  ASSERT_TRUE( rando.isDivisbleBy(0,-3));
  ASSERT_TRUE( rando.isDivisbleBy(-3,0));
  ASSERT_FALSE( rando.isDivisbleBy(0,0));
}

TEST(RandoTest, DivisbleByPositiveAndNegativeNumbers)
{
  Rando rando;
  ASSERT_TRUE( rando.isDivisbleBy(2,-4));
  ASSERT_TRUE( rando.isDivisbleBy(4,-2));
  ASSERT_TRUE( rando.isDivisbleBy(-2,4));
  ASSERT_TRUE( rando.isDivisbleBy(-4,2));
  ASSERT_FALSE( rando.isDivisbleBy(3,-5));
  ASSERT_FALSE( rando.isDivisbleBy(5,-3));
  ASSERT_FALSE( rando.isDivisbleBy(-3,5));
  ASSERT_FALSE( rando.isDivisbleBy(-5,3));
}

TEST(RandoTest, DivisbleByNegativeNumbers)
{
  Rando rando;
  ASSERT_TRUE( rando.isDivisbleBy(-2,-4));
  ASSERT_TRUE( rando.isDivisbleBy(-4,-2));
  ASSERT_FALSE( rando.isDivisbleBy(-3,-5));
  ASSERT_FALSE( rando.isDivisbleBy(-5,-3));
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
