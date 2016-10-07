/**
 *Marianna Matousek
 *multipy.cpp
 *CS23001
 *This program inputs bigint from a file, multiplies 
 *them and prints out the result.
 */
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "bigint.hpp"

int main() {
  std::ifstream in("data1-2.txt");    // Define stream for input
  if (!in) {                           // Make sure it opened correctly.
    std::cerr << "Could not open data1-2.txt, exiting." << std::endl;
    exit(1);
  }



  //Until end of file
  while (!in.eof()) {
    bigint bi1;
    bigint bi2;

    //Read two bigints
    in >> bi1 >> bi2;

    //just in case, check if reached end of file again
    //I haven't had time to test my input operator
    if (in.eof()) {
      break;
    }

    //Print them out
    std::cout << "Bigint 1: \n" << bi1 << "\n"
	      << "Bigint 2: \n" << bi2 << "\n";


    //Add them together
    bigint result = bi1 * bi2;

    //Print out result
    std::cout << "Result: \n" << result << "\n\n";

  }

  in.close();
  return 0;
}

