//  String class test program
//
//  Tests: XXX
//

#include "string.hpp"
#include <cassert>
#include <iostream>

//===========================================================================
int main()
{
	{
		//find string searting from start
		//------------------------------------------------------
		// SETUP FIXTURE
		String  str1("abcabcabc");
		String str2("ab");
		// TEST
		int result = str1.findstr(0, str2);

		// VERIFY
		assert(str1 == "abcabcabc");
		assert(str2 == "ab");
		assert(result == 0);
	}

	{
		//find string searting > 0
		//------------------------------------------------------
		// SETUP FIXTURE
		String  str1("abcabcabc");
		String str2("ab");
		// TEST
		int result = str1.findstr(2, str2);

		// VERIFY
		assert(str1 == "abcabcabc");
		assert(str2 == "ab");
		assert(result == 3);
	}
	
	{
		//find string exactly like string
		//------------------------------------------------------
		// SETUP FIXTURE
		String  str1("abcabcabc");
		String str2("abcabcabc");
		// TEST
		int result = str1.findstr(0, str2);

		// VERIFY
		assert(str1 == "abcabcabc");
		assert(str2 == "abcabcabc");
		assert(result == 0);
	}

	{
		//find string that is too long like string starting > 0
		//------------------------------------------------------
		// SETUP FIXTURE
		String  str1("abcabcabc");
		String str2("abcabcabc");
		// TEST
		int result = str1.findstr(1, str2);

		// VERIFY
		assert(str1 == "abcabcabc");
		assert(str2 == "abcabcabc");
		assert(result == -1);
	}

	{
		//find string that doesn't exist
		//------------------------------------------------------
		// SETUP FIXTURE
		String  str1("abcabcabc");
		String str2("zz");
		// TEST
		int result = str1.findstr(0, str2);

		// VERIFY
		assert(str1 == "abcabcabc");
		assert(str2 == "zz");
		assert(result == -1);
	}

	{
		//find a character string
		//------------------------------------------------------
		// SETUP FIXTURE
		String  str1("abcabcabc");
		String str2("c");
		// TEST
		int result = str1.findstr(0, str2);

		// VERIFY
		assert(str1 == "abcabcabc");
		assert(str2 == "c");
		assert(result == 2);
	}
	std::cout << "Done testing findstr()." << std::endl;
}

