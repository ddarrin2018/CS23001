#include <iostream>
#include "object_construction.hpp"

//Wasn't really clear if we were supposed to actually
//write code or not for these...

Test::Test(){
  //int a = new size; 
  std::cout << "called def ctor." << std::endl;
}

Test::Test(const Test& rhs){
  //code
  std::cout << "called copy ctor." << std::endl;
}

Test::~Test(){
  //code
  std::cout << "called destructor." << std::endl;
}

Test& Test::operator=(const Test &rhs){
  //code
	Test result;
  std::cout << "called copy ctor." << std::endl;
  return result; 
}


