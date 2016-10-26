//  String class test program
//
//  Tests: substring
//

#include "string.hpp"
#include <cassert>
#include <iostream>

//===========================================================================
int main ()
{
	{
		//start == 0 && end < length
		//------------------------------------------------------
		// SETUP FIXTURE
		String str1("alligator");

		// TEST
		String result = str1.substr(0,2);

		// VERIFY
		assert(str1 == "alligator");
		assert(result == "all");

	}

	{
		//start ==0 && end > length
		//------------------------------------------------------
		// SETUP FIXTURE
		String str1("alligator");

		// TEST
		String result = str1.substr(0, 11);

		// VERIFY
		assert(str1 == "alligator");
		assert(result == "");
	}
    
	{
		//start >0 && end < length
		//------------------------------------------------------
		// SETUP FIXTURE
		String str1("alligator");

		// TEST
		String result = str1.substr(2, 4);

		// VERIFY
		assert(str1 == "alligator");
		assert(result == "lig");
	}

	{
		//start < 0 && end < length
		//------------------------------------------------------
		// SETUP FIXTURE
		String str1("alligator");

		// TEST
		String result = str1.substr(-3, 4);

		// VERIFY
		assert(str1 == "alligator");
		assert(result == "allig");
	}
    std::cout << "Done testing substr()." << std::endl;
}

