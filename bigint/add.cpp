/**
 *Marianna Matousek
 *add.cpp
 *CS23001
 *This program inputs bigint from a file, adds them and prints out the result. 
 */
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "bigint.hpp"

int main() {
  std::ifstream in("data1-1.txt");    // Define stream for input
  if (!in) {                           // Make sure it opened correctly.
    std::cerr << "Could not open data1-1.txt, exiting." << std::endl;
    exit(1);
  }
  
  

  //Until end of file
  while (!in.eof()) {
    bigint bi1;
    bigint bi2;
    
    //Read two bigints
    in >> bi1 >> bi2;
    
    //check if reached end of file again
    //??am i doing this wrong? 
    if (in.eof()) {
      break;
    }

    //Print them out
    std::cout << "Bigint 1: \n" << bi1 << "\n" 
	      << "Bigint 2: \n" << bi2 << "\n";


    //Add them together
    bigint result = bi1 + bi2;

    //Print out results
    std::cout << "Result: \n"<< result << "\n\n"; 

  }

  in.close();
  return 0;
}

