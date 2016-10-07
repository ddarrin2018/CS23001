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
    //Test: Small bigint times 1
    // Setup fixture
    bigint bi(3);

    // Test 
    bi = bi.times_single_digit(1);

    // Verify
    assert(bi == 3);
  }

  {
    //------------------------------------------------------
    //Test: Large bigint times 1
    // Setup fixture
    bigint bi("346523456787645678764571234");

    // Test 
    bi = bi.times_single_digit(1);

    // Verify
    assert(bi == "346523456787645678764571234");
  }

  {
    //------------------------------------------------------
    //Test: small bigint times 0
    // Setup fixture
    bigint bi(3);

    // Test 
    bi = bi.times_single_digit(0);

    // Verify
    assert(bi == 0);
  }

  {
    //------------------------------------------------------
    //Test: large bigint times 0
    // Setup fixture
    bigint bi("25433997635463008134567898765");

    // Test 
    bi = bi.times_single_digit(0);

    // Verify
    assert(bi == 0);
  }

  {
    //------------------------------------------------------
    //Test:Zero bigint times non zero digit
    // Setup fixture
    bigint bi(0);

    // Test 
    bi = bi.times_single_digit(5);

    // Verify
    assert(bi == 0);
  }

  {
    //------------------------------------------------------
    //Test: single digit bigint times 9
    // Setup fixture
    bigint bi(2);

    // Test 
    bi = bi.times_single_digit(9);

    // Verify
    assert(bi == 18);
  }

  {
    //------------------------------------------------------
    //Test: three digit bigint times digit carry from end
    // Setup fixture
    bigint bi(128);

    // Test 
    bi = bi.times_single_digit(2);

    // Verify
    assert(bi == 256);
  }

  {
    //------------------------------------------------------
    //Test: three digit bigint times digit carry from middle
    // Setup fixture
    bigint bi(182);

    // Test 
    bi = bi.times_single_digit(2);

    // Verify
    assert(bi == 364);
  }

  {
    //------------------------------------------------------
    //Test: three digit bigint times digit carry begining
    // Setup fixture
    bigint bi(821);

    // Test 
    bi = bi.times_single_digit(2);

    // Verify
    assert(bi == 1642);
  }

  {
    //------------------------------------------------------
    //Test: Large bigint times 9 
    // Setup fixture
    bigint bi("456780987652345678760654323456");

    // Test 
    bi = bi.times_single_digit(9);

    // Verify
    assert(bi == "4111028888871111108845888911104");
  }

  {
    //------------------------------------------------------
    //Test: Bigint that is all nines times digit
    // Setup fixture
    bigint bi("999999999999999999");

    // Test 
    bi = bi.times_single_digit(8);

    // Verify
    assert(bi == "7999999999999999992");
}

std::cout << "Done testing bigint * single digit" << std::endl;

}
