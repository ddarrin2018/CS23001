// bigint Test Program
//
// Tests:  subscript, uses ==
//
#include <iostream>
#include <cassert>
#include "bigint.hpp"

//===========================================================================
int main() {

  {
    // Setup
    bigint bi(4);

    // Test 
    int digit = bi[0];

    // Verify
    assert(bi == 4);
    assert(digit == 4);
  }

  {
    //Test: start of bigint
    // Setup
    bigint bi(200001);

    // Test
    int digit = bi[5];

    // Verify
    assert(bi == 200001);
    assert(digit == 2);
  }

  {
    //Test: end  of bigint
    // Setup
    bigint bi(200001);

    // Test
    int digit = bi[0];

    // Verify
    assert(bi == 200001);
    assert(digit == 1);
  }

  {
    //Test: middle of bigint
    // Setup
    bigint bi(123456);

    // Test
    int digit = bi[2];

    // Verify
    assert(bi == 123456);
    assert(digit == 4);
  }



  std::cout << "Done testing subscript." << std::endl;
}

