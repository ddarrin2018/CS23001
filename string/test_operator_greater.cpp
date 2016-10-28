//  String class test program
//
//  bool    operator>=      (const String&, const String&);
//

#include "string.hpp"
#include <cassert>
#include <iostream>

//===========================================================================
int main()
{
	{
		//empty String < empty String
		//------------------------------------------------------
		// SETUP FIXTURE
		String str1;
		String str2;

		// TEST
		bool result = operator>(str1, str2);

		// VERIFY
		assert(str1 == "");
		assert(str2 == "");
		assert(result == false);

		std::cout << str1;
		std::cout << (result ? (" > ") : (" !< "));
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
		bool result = operator>(str1, str2);

		// VERIFY
		assert(str1 == "");
		assert(str2 == "a");
		assert(result == false);

		std::cout << str1;
		std::cout << (result ? (" > ") : (" <= "));
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
		bool result = operator>(str1, str2);

		// VERIFY
		assert(str1 == "a");
		assert(str2 == "");
		assert(result == true);

		std::cout << str1;
		std::cout << (result ? (" > ") : (" <= "));
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
		bool result = operator>(str1, str2);

		// VERIFY
		assert(str1 == "alligator");
		assert(str2 == "b");
		assert(result == false);

		std::cout << str1;
		std::cout << (result ? (" > ") : (" <= "));
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
		bool result = operator>(str1, str2);

		// VERIFY
		assert(str1 == "abc");
		assert(str2 == "abc");
		assert(result == false);

		std::cout << str1;
		std::cout << (result ? (" > ") : (" <= "));
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
		bool result = operator>(str1, str2);

		// VERIFY
		assert(str1 == "ABC");
		assert(str2 == "abc");
		assert(result == false);

		std::cout << str1;
		std::cout << (result ? (" > ") : (" <= "));
		std::cout << str2;
		std::cout << std::endl;
	}
	{
		//equivalents Strings
		//------------------------------------------------------
		// SETUP FIXTURE
		String str2("ABC");
		String str1("abc");

		// TEST
		bool result = operator>(str1, str2);

		// VERIFY
		assert(str2 == "ABC");
		assert(str1 == "abc");
		assert(result == true);

		std::cout << str1;
		std::cout << (result ? (" > ") : (" <= "));
		std::cout << str2;

	}

	std::cout<<std::endl << "Done testing String > String" << std::endl;
}

