//  String class test program
//
//  Tests: bool    operator<     (const String&)  const;
//

#include "string.hpp"
#include <cassert>
#include <iostream>

//===========================================================================
int main ()
{
	{
		//empty String < empty String
		//------------------------------------------------------
		// SETUP FIXTURE
		String str1;
		String str2;

		// TEST
		bool result = str1.operator<(str2);

		// VERIFY
		assert(str1 == "");
		assert(str2 == "");
		assert(result == false);

		std::cout << str1;
		std::cout << (result ? (" < ") : (" !< "));
		std::cout << str2;
		std::cout << std::endl;

	}

	{
		//empty String < String
		//------------------------------------------------------
		// SETUP FIXTURE
		String str1;
		String str2("a");

		// TEST
		bool result = str1.operator<(str2);

		// VERIFY
		assert(str1 == "");
		assert(str2 == "a");
		assert(result == true);

		std::cout << str1;
		std::cout << (result ? (" < ") : (" !< "));
		std::cout << str2;
		std::cout << std::endl;
	}

	{
		//String < empty String
		//------------------------------------------------------
		// SETUP FIXTURE
		String str1("a");
		String str2;

		// TEST
		bool result = str1.operator<(str2);

		// VERIFY
		assert(str1 == "a");
		assert(str2 == "");
		assert(result == false);

		std::cout << str1;
		std::cout << (result ? (" < ") : (" !< "));
		std::cout << str2;
		std::cout << std::endl;
	}

	
  
	{
		//equivalents Strings
		//------------------------------------------------------
		// SETUP FIXTURE
		String str1("alligator");
		String str2("b");

		// TEST
		bool result = str1.operator<(str2);

		// VERIFY
		assert(str1 == "alligator");
		assert(str2 == "b");
		assert(result == true);

		std::cout << str1;
		std::cout << (result ? (" < ") : (" !< "));
		std::cout << str2;
		std::cout << std::endl;
	}

	{
		//equivalents Strings
		//------------------------------------------------------
		// SETUP FIXTURE
		String str1("abc");
		String str2("abc");

		// TEST
		bool result = str1.operator<(str2);

		// VERIFY
		assert(str1 == "abc");
		assert(str2 == "abc");
		assert(result == false);

		std::cout << str1;
		std::cout << (result ? (" < ") : (" !< "));
		std::cout << str2;
		std::cout << std::endl;
	}

	{
		//equivalents Strings
		//------------------------------------------------------
		// SETUP FIXTURE
		String str1("ABC");
		String str2("abc");

		// TEST
		bool result = str1.operator<(str2);

		// VERIFY
		assert(str1 == "ABC");
		assert(str2 == "abc");
		assert(result == true);

		std::cout << str1;
		std::cout << (result ? (" < ") : (" !< "));
		std::cout << str2;
		std::cout << std::endl;
	}


	{
		//equivalents Strings
		//------------------------------------------------------
		// SETUP FIXTURE
		String str1("ab");
		String str2("abc");

		// TEST
		bool result = str1.operator<(str2);

		// VERIFY
		assert(str1 == "ab");
		assert(str2 == "abc");
		assert(result == true);

		std::cout << str1;
		std::cout << (result ? (" < ") : (" !< "));
		std::cout << str2;
		std::cout << std::endl;
	}

    std::cout << "Done testing String < String" << std::endl;
}

