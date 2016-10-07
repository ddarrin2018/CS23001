// bigint Test Program
//
// Tests:  times_10, uses ==
//
#include <iostream>
#include <cassert>
#include "bigint.hpp"

//===========================================================================
int main() {
  {
    //------------------------------------------------------
    //Test: bigint times 10^0
    // Setup fixture
    bigint bi(3);

    // Test 
    bi = bi.times10(0);


    assert(bi == 3);
  }
  {
    //------------------------------------------------------
    //Test: multiple digit bigint times 10^0
    // Setup fixture
    bigint bi(30043);

    // Test 
    bi = bi.times10(0);


    assert(bi == 30043);
  }
  {
    //------------------------------------------------------
    //Test: bigint times 10^1
    // Setup fixture
    bigint bi(3);

    // Test 
    bi = bi.times10(1);


    assert(bi == 30);
  }

  {
    //------------------------------------------------------
    //Test: bigint times 10^0
    // Setup fixture
    bigint bi("23456787654345678456");

    // Test 
    bi = bi.times10(1);


    assert(bi == "234567876543456784560");
  }

  {
    //------------------------------------------------------
    //Test: bigint times 10^20
    // Setup fixture
    bigint bi(3);

    // Test 
    bi = bi.times10(20);


    assert(bi == "300000000000000000000");
  }

  {
    //------------------------------------------------------
    //Test: large bigint times 10^20
    // Setup fixture
    bigint bi("23456787654345678456");

    // Test 
    bi = bi.times10(20);


    assert(bi == "2345678765434567845600000000000000000000");
  }

  {
    //------------------------------------------------------
    //Test: bigint ending in 0 times 10^1
    // Setup fixture
    bigint bi(300);

    // Test 
    bi = bi.times10(1);


    assert(bi == 3000);
  }



  std::cout << "Done testing times10" << std::endl;
}
