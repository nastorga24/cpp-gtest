#include "rando.h"
//#include <stdlib.h>
//Natalie Astorga
//09/22/2015
//CSCI 430

/**
 * Worry if only one child is smiling or if all children are smiling
**/
bool Rando::shouldWorry(bool childASmile, bool childBSmile, bool childCSmile)
{
	if( childASmile && childBSmile && childCSmile )
		return true;
	else if( childASmile ^ childBSmile ^ childCSmile )
		return true;
	else
		return false;
}
/**
 * Determines if first or second are evenly divisible by the other.
**/
bool Rando::isDivisbleBy(int first, int second)
{
  if(first == 0 && second == 0)
    return false;
  else if((first == 0) ^ (second == 0))
    return true;
  else if(first % second == 0)
    return true;
  else if(second % first == 0)
    return true;
  else
    return false;
}

/**
 * Given a number, num, says whether or not that number is prime
 * (that is, only evenly divisible by itself and 1. For the sake
 * of this function, do NOT consider 0 prime)
**/
bool Rando::isPrime(int num)
{
  int i;
  int absoluteNum = (num < 0) ? -num : num;
  if(num == 0)
    return false;
  for(i = 2; i*i <= absoluteNum; i++)
  {
    if(num%i == 0)
      return false;
  }
	return true;
}

/**
 * Given two numbers, first and second, return the value of the one
 * that is closest to zero without actually being zero.
**/
int Rando::nearestToZero(int a, int b)
{
  int absoluteA = (a < 0) ? -a : a;
  int absoluteB = (b < 0) ? -b : b;
  if(a == 0)
    return b;
  else if(b==0)
    return a;
  else  
  {
    if(absoluteA < absoluteB)
      return a;
     else
       return b;
  }
	return 0;
}
