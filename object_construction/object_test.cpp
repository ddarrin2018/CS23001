/*Marianna Matousek
*Lab 6
*object_test.cpp
*/

#include <iostream>
#include "object_construction.hpp"

int main(){
	Test s;
	Test a(s);
	
	//how to call a destructor
	//without writing code?
	a.~Test(); 

	Test b;
	b = a; 


  return 0; 

  

}
