// bigint Test Program
//
// Tests:  int constructor, uses ==
//
#include <iostream>
#include <cassert>
#include "bigint.hpp"


//===========================================================================
int main() {
  {
    //------------------------------------------------------
    //Test: Adding to zeroes
    // Setup fixture
    bigint left(0);
    bigint right(0);
    bigint result;

    // Test 
    result = left + right;

    // Verify
    assert(left == 0);
    assert(right == 0);
    assert(result == 0);
  }

  {
    //------------------------------------------------------
    //Test: Adding a single digit int and a 0
    // Setup fixture
    bigint left(1);
    bigint right(0);
    bigint result;

    // Test
    result = left + right;

    // Verify
    assert(left == 1);
    assert(right == 0);
    assert(result == 1);
  }

  {
    //------------------------------------------------------
    //Test: Adding a 0 and a single digit //?needed
    // Setup fixture
    bigint left(0);
    bigint right(1);
    bigint result;

    // Test
    result = left + right;

    // Verify
    assert(left == 0);
    assert(right == 1);
    assert(result == 1);
  }

  {
    //------------------------------------------------------
    //Test: Adding two single digit numbers, no carry
    // Setup fixture
    bigint left(2);
    bigint right(3);
    bigint result;

    // Test
    result = left + right;

    // Verify
    assert(left == 2);
    assert(right == 3);
    assert(result == 5);
  }

  {
    //------------------------------------------------------
    //Test: Adding two single digit numbers, with carry
    // Setup fixture
    bigint left(9);
    bigint right(5);
    bigint result;

    // Test
    result = left + right;

    // Verify
    assert(left == 9);
    assert(right == 5);
    assert(result == 14);
  }
  {
    //------------------------------------------------------
    //Test: Adding two multiple digit numbers digit number, no carry
    // Setup fixture
    bigint left(11);
    bigint right(23);
    bigint result;

    // Test
    result = left + right;

    // Verify
    assert(left == 11);
    assert(right == 23);
    assert(result == 34);
  }

  {
    //------------------------------------------------------
    //Test: Adding two multiple digit numbers, with carry on ones
    // Setup fixture
    bigint left(23);
    bigint right(18);
    bigint result;

    // Test
    result = left + right;

    // Verify
    assert(left == 23);
    assert(right == 18);
    assert(result == 41);
  }
  {
    //------------------------------------------------------
    //Test: Adding two multiple digit numbers, with cary on tens
    // Setup fixture
    bigint left(23);
    bigint right(93);
    bigint result;

    // Test
    result = left + right;

    // Verify
    assert(left == 23);
    assert(right == 93);
    assert(result == 116);
  }

  {
    //------------------------------------------------------
    //Test: Adding two single digit numbers, with carry on tens and one
    // Setup fixture
    bigint left(99);
    bigint right(33);
    bigint result;

    // Test
    result = left + right;

    // Verify
    assert(left == 99);
    assert(right == 33);
    assert(result == 132);
  }

  {
    //------------------------------------------------------
    //Test: Adding two multi digit numbers
    // Setup fixture
    bigint left("1236547878798978");
    bigint right("234423435346457568678");
    bigint result;

    // Test
    result = left + right;

    // Verify
    assert(left == "1236547878798978");
    assert(right == "234423435346457568678");
    assert(result == "234424671894336367656");

  }

  {
    //------------------------------------------------------
    //Test: Adding two multi digit numbers with a zero in same place
    // Setup fixture
    bigint left("1236047878798978");
    bigint right("234403435346457568678");
    bigint result;

    // Test
    result = left + right;

    // Verify
    assert(left == "1236047878798978");
    assert(right == "234403435346457568678");
    assert(result == "234404671394336367656");
  }










  std::cout << "Done with testing addition." << std::endl;
}

