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
        assert(result == (STRING_SIZE-1));
    }
	{
		//------------------------------------------------------
		// SETUP FIXTURE
		String  str("abc");
		// TEST
		int result = str.capacity();
		// VERIFY
		assert(str == "abc");
		assert(result == (STRING_SIZE - 1));
	}
    
    std::cout << "Done testing capacity()." << std::endl;
}

