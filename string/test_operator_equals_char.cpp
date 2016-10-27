//  String class test program
//
//  Tests: bool    operator==    (const String&)  const;
//

#include "string.hpp"
#include <cassert>
#include <iostream>

//===========================================================================
int main()
{
	{


		// Setup
		String str1("abc");
		String str2("a");

		// Test
		assert(!(str1==str2));
		// Verify
		std::cout << str1;
		std::cout << " != ";
		std::cout << str2;
		std::cout << std::endl;

	}

	{


		// Setup
		String str1("a");
		String str2("abc");

		// Test
		assert(!(str1 == str2));
		// Verify
		std::cout << str1;
		std::cout << " != ";
		std::cout << str2;
		std::cout << std::endl;

	}

	{


		// Setup
		String str1("abc");
		String str2("abc");

		// Test
		assert(str1 == str2);
		// Verify
		std::cout << str1;
		std::cout << " == ";
		std::cout << str2;
		std::cout << std::endl;

	}



	// ADD ADDITIONAL TESTS AS NECESSARY

	std::cout << "Done testing operator==" << std::endl;
}

