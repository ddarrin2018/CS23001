//  String class test program
//
//  Tests: bool    operator<       (const char[],  const String&);
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
		char a[] = "";

		// TEST
		bool result = operator<(a,str1);

		// VERIFY
		assert(str1 == "");
		assert(a[0] == '\0');
		assert(result == false);

		std::cout << a;
		std::cout << (result ? (" < ") : (" !< "));
		std::cout << str1;
		std::cout << std::endl;

	}

	{
		//empty String < empty String
		//------------------------------------------------------
		// SETUP FIXTURE
		String str1;
		char a[] = "a";

		// TEST
		bool result = operator<(a, str1);

		// VERIFY
		assert(str1 == "");
		assert((a[0] == 'a' && a[1] == '\0'));
		assert(result == false);

		std::cout << a;
		std::cout << (result ? (" < ") : (" !< "));
		std::cout << str1;
		std::cout << std::endl;

	}

{
		//empty String < empty String
		//------------------------------------------------------
		// SETUP FIXTURE
		String str1("a");
		char a[] = "";

		// TEST
		bool result = operator<(a, str1);

		// VERIFY
		assert(str1 == "a");
		assert(a[0] == '\0');
		assert(result == true);

		std::cout << a;
		std::cout << (result ? (" < ") : (" !< "));
		std::cout << str1;
		std::cout << std::endl;

	}

	
  
	{
		//equivalents Strings
		//------------------------------------------------------
		// SETUP FIXTURE
		String str1("alligator");
		char a [] = "b";

		// TEST
		bool result = operator<(a, str1);

		// VERIFY
		assert(str1 == "alligator");
		assert(a[0] == 'b' && a[1] == '\0');
		assert(result == false);

		std::cout << a;
		std::cout << (result ? (" < ") : (" !< "));
		std::cout << str1;
		std::cout << std::endl;
	}

	{
		//empty String < empty String
		//------------------------------------------------------
		// SETUP FIXTURE
		String str1("abc");
		char a[] = "abc";

		// TEST
		bool result = operator<(a, str1);

		// VERIFY
		assert(str1 == "abc");
		assert(a[0] == 'a' && a[1] == 'b' && a[2] == 'c' && a[3] == '\0');
		assert(result == false);

		std::cout << a;
		std::cout << (result ? (" < ") : (" !< "));
		std::cout << str1;
		std::cout << std::endl;


	}

	{
		//empty String < empty String
		//------------------------------------------------------
		// SETUP FIXTURE
		String str1("abc");
		char a[] = "ABC";

		// TEST
		bool result = operator<(a, str1);

		// VERIFY
		assert(str1 == "abc");
		assert(a[0] == 'A' && a[1] == 'B' && a[2] == 'C' && a[3] == '\0');
		assert(result == true);

		std::cout << a;
		std::cout << (result ? (" < ") : (" !< "));
		std::cout << str1;
		std::cout << std::endl;


	}



    std::cout << "Done testing char[] < String" << std::endl;
}

