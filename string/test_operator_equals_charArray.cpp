//  String class test program
//
//  Tests: bool    operator==      (const char[],  const String&);
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
		char a[] = "def";

		// Test
		bool result = (a == str1);
		assert(!(a==str1));
		// Verify
		std::cout << str1;
		std::cout << (result ? "==": " != ");
		std::cout << a;
		std::cout << std::endl;

	}
	
	{


		// Setup
		String str1("a");
		char a[] = "abc";

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
		String str1("abc");
		char a[] = "abc";

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
		char a[] = "abc";

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

	std::cout << "Done testing operator==" << std::endl;
}

