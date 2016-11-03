//  String class test program
//
//  Tests: char array constructor
//

#include "string.hpp"
#include <cassert>
#include <iostream>

//===========================================================================
int main ()
{
    {	
	//char array constructor 
	//one character long string
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  str("a");

        // VERIFY
        assert(str[0] == 'a');
		assert(str[1] == '\0');

    }

    {
	//char array constructor multiple character array
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  str("abc");

        // VERIFY
        assert(str[0] == 'a');
		assert(str[1] == 'b');
		assert(str[2] == 'c');
		assert(str[3] == '\0');
    }

    {
      //char array constructor multiple character array
      //empty string
      //------------------------------------------------------
      // SETUP FIXTURE
      
      
      // TEST
      String  str("");

      // VERIFY
      assert(str[0] == '\0');
    }

	std::cout << "Done testing char array constructor." << std::endl;
      
	
}

