//  String class test program
//
//  Tests: capacity
//

#include "string.hpp"
#include <cassert>
#include <iostream>

//===========================================================================
int main ()
{
    {
        //------------------------------------------------------
        // SETUP FIXTURE
		String  str;
        // TEST
        int result = str.capacity();

        // VERIFY
        assert(str == "");
        assert(result == 0);
    }
	
	
	{
		//------------------------------------------------------
		// SETUP FIXTURE
		String  str('a');

		// TEST
		int result = str.capacity();

		// VERIFY
		assert(str  == "a");
		assert(result == 1);
	}

	{
		//------------------------------------------------------
		// SETUP FIXTURE
		String  str("abc");
		// TEST
		int result = str.capacity();
		// VERIFY
		assert(str == "abc");
		assert(result == 3);
	}
    

    std::cout << "Done testing capacity()." << std::endl;
}

