//  String class test program
//
//  Tests: XXX
//

#include "string.hpp"
#include <cassert>
#include <iostream>

//===========================================================================
int main ()
{
    {
		//find char searching from chars position
        //------------------------------------------------------
        // SETUP FIXTURE
		String  str("abcabc");

        // TEST
        int result = str.findchar(0, 'a');

        // VERIFY
        assert(str    == "abcabc");
        assert(result == 0);
    }

	{
		//find a char searching from befor its position
		//------------------------------------------------------
		// SETUP FIXTURE
		String  str("abcabc");

		// TEST
		int result = str.findchar(1, 'a');

		// VERIFY
		assert(str == "abcabc");
		assert(result == 3);
	}
  
	{
		//find a char searching past its position
		//------------------------------------------------------
		// SETUP FIXTURE
		String  str("abcabc");

		// TEST
		int result = str.findchar(4, 'a');

		// VERIFY
		assert(str == "abcabc");
		assert(result == -1);
	}
    
	{
		//find a char that isn't in string
		//------------------------------------------------------
		// SETUP FIXTURE
		String  str("abcabc");

		// TEST
		int result = str.findchar(0, 'z');

		// VERIFY
		assert(str == "abcabc");
		assert(result == -1);
	}
	{
		//find a char that isn't in string
		//------------------------------------------------------
		// SETUP FIXTURE
		String  str("abcabc");

		// TEST
		int result = str.findchar(6, 'a');

		// VERIFY
		assert(str == "abcabc");
		assert(result == -1);
	}
	std::cout << "Done testing findchar()." << std::endl;
}

