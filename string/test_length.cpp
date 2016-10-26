//  String class test program
//
//  Tests: length member function
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
        String  str("abc");

        // TEST
        int result = str.length();

        // VERIFY
        assert(str  == "abc");
        assert(result == 3);
    }

	{
		//------------------------------------------------------
		// SETUP FIXTURE
		String  str("");

		// TEST
		int result = str.length();

		// VERIFY
		assert(str == "");
		assert(result == 0);
	}

	{	
		//------------------------------------------------------
		// SETUP FIXTURE
		String  str('a');

		// TEST
		int result = str.length();

		// VERIFY
		assert(str == 'a');
		assert(result == 1);
	}
	{
		//------------------------------------------------------
		// SETUP FIXTURE
		String  str;

		// TEST
		int result = str.length();

		// VERIFY
		assert(str == "");
		assert(result == 0);
	}
	std::cout << "Done testing length()." << std::endl;
}

