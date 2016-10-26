//  String class test program
//
//  Tests: char array + String
//

#include "string.hpp"
#include <cassert>
#include <iostream>

//===========================================================================
int main()
{

	{
		//charArray plus empty String
		//------------------------------------------------------
		// SETUP FIXTURE
		char ch = '\0';
		String str;

		// TEST
		String result = ch + str;

		// VERIFY
		assert(ch == '\0');
		assert(str == "");
		assert(result == "");
	}

	{
		//charArray plus empty String
		//------------------------------------------------------
		// SETUP FIXTURE
		char ch = 'a';
		String str("bc");

		// TEST
		String result = ch + str;

		// VERIFY
		assert(ch == 'a');
		assert(str == "bc");
		assert(result == "abc");
	}

	{
		//charArray plus empty String
		//------------------------------------------------------
		// SETUP FIXTURE
		char ch = 'a';
		String str("");

		// TEST
		String result = ch + str;

		// VERIFY
		assert(ch == 'a');
		assert(str == "");
		assert(result == "a");
	}
	
	std::cout << "Done testing char plus String" << std::endl;

}

