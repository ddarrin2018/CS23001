/*Marianna Matousek
*Lab6
*object_construction.hpp
*/

#include <iostream>

class Test{
public:
  Test();
  Test(const Test& rhs);
  ~Test();
  Test& operator=(const Test & rhs);


private:
  int *size; 
  int cap; 

};
