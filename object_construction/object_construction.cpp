#include <iostream>
#include "object_construction.hpp"

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
  std::cout << "called copy ctor." << std::endl;
}
