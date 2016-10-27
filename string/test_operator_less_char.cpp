//  String class test program
//
// bool    operator<       (const char[],  const String&)
//

#include "string.hpp"
#include <cassert>
#include <iostream>

//===========================================================================
int main ()
{
	{
		//
		//------------------------------------------------------
		// SETUP FIXTURE
		String str1("a");
		char ch = 'a';

		// TEST
		bool result = operator<(ch, str1);

		// VERIFY
		assert(str1 == "a");
		assert(ch== 'a');
		assert(result == false);

		std::cout << ch;
		std::cout << (result ? (" < ") : (" !< "));
		std::cout << str1;
		std::cout << std::endl;

	}

	{
		
		//------------------------------------------------------
		// SETUP FIXTURE
		String str1("assess");
		char ch = 'b';

		// TEST
		bool result = operator<(ch, str1);

		// VERIFY
		assert(str1 == "assess");
		assert(ch == 'b');
		assert(result == false );

		std::cout << ch;
		std::cout << (result ? (" < ") : (" !< "));
		std::cout << str1;
		std::cout << std::endl;

	}

	{

		//String < empty String
		//------------------------------------------------------
		// SETUP FIXTURE
		String str1("assess");
		char ch = 'A';

		// TEST
		bool result = operator<(ch, str1);

		// VERIFY
		assert(str1 == "assess");
		assert(ch == 'A');
		assert(result == true);

		std::cout << ch;
		std::cout << (result ? (" < ") : (" !< "));
		std::cout << str1;
		std::cout << std::endl;
	
	}
	{

		//String < empty String
		//------------------------------------------------------
		// SETUP FIXTURE
		String str1("assess");
		char ch = '\0';

		// TEST
		bool result = operator<(ch, str1);

		// VERIFY
		assert(str1 == "assess");
		assert(ch == '\0');
		assert(result == true);

		std::cout << ch;
		std::cout << (result ? (" < ") : (" !< "));
		std::cout << str1;
		std::cout << std::endl;

	}

    std::cout << "Done testing char < String" << std::endl;
}

