//  String class test program
//
//  Tests: bool    operator==      (const char,  const String&);
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
		char a = 'a';

		// Test
		bool result = (a == str1);
		assert(!(a == str1));
		// Verify
		std::cout << str1;
		std::cout << (result ? "==" : " != ");
		std::cout << a;
		std::cout << std::endl;

	}

	{


		// Setup
		String str1("a");
		char a = 'a';

		// Test
		bool result = (a == str1);
		assert(a == str1);

		// Verify
		std::cout << str1;
		std::cout << (result ? " == " : " != ");
		std::cout << a;
		std::cout << std::endl;

	}

	{


		// Setup
		String str1;
		char a = '\0';

		// Test
		bool result = (a == str1);
		assert(a == str1);

		// Verify
		std::cout << str1;
		std::cout << (result ? " == " : " != ");
		std::cout << a;
		std::cout << std::endl;



	}

	{


		// Setup
		String str1;
		char a = 'c';

		// Test
		bool result = (a == str1);
		assert(!(a == str1));
		// Verify
		std::cout << str1;
		std::cout << (result ? " == " : " != ");
		std::cout << a;
		std::cout << std::endl;



	}

	// ADD ADDITIONAL TESTS AS NECESSARY

	std::cout << "Done testing operator== char" << std::endl;
}

