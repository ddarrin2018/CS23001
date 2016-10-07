/**
 *Marianna Matousek
 *factorial.cpp
 *CS23001
 *This program prints out the factorial of a bigint and the number of
 *leading zeroes that factorial has.
 */

#include <iostream>
#include <cstdlib>
#include "bigint.hpp"

int main() {
  bigint bi(100);
  
  bigint factorial = bi.factorial(); 

  std::cout << bi << "! is equal to:\n" << factorial << "\n\n";

  int zeroes = bi.trailing_zeroes(); 
  
  std::cout << bi << "! has " << zeroes << " trailing zero(es).\n\n"; 
  
  std::cout << "I calculated this using three methods: \n"
	    << "1: oveloaded minus operator (accurate only for results >=0)\n"
	    << "2: a factorial method\n"
	    << "3: a trailing_zeroes method\n\n"

	    << "In a while loop, using the minus operator I subtracted 1\n"
	    << "from a temporary bigint variable which I multiplied by the\n"
	    << "result where I kept the running total product.\n"
	    << "When the temporary bigint becomes zero the result variable\n"
	    <<" holds the factorial value of the object.\n\n"

	    << "In the trailing_zeroes function I count the number of zeroes\n"
	    << "encountered before the while loop reaches a non zero digit in\n"
	    <<" the bigintArray.\n"
	    << "-------------------------------------------------------\n"
	    << "Using mathematics: a way to calculate the number of trailing zeroes\n"
	    << "is to divide the number by 5 until a quotient of less than 1 is\n"
	    << "reached. Add together all the whole number results and that is the\n"
	    << "answer. \nExample using 100!: \n"
	    << "100 / 5 = 20\n"
	    << "20 / 5 = 4\n"
	    << "4/ 5 = .8\n"
	    << "Total = 20 + 4\n"
	    << "The answer is 24.\n\n";

  return 0;
}

