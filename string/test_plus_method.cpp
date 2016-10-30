//  String class test program
//
//  Tests: Concatination String + String
//

#include "string.hpp"
#include <cassert>
#include <iostream>

//===========================================================================
int main ()
{
    {
		//empty plus empty
        //------------------------------------------------------
        // SETUP FIXTURE
		String  str1;
		String str2;

        // TEST
		String result = str1.operator+(str2);

        // VERIFY
        assert(str1 == "");
		assert(str2 == "");
        assert(result == "");
    }
	
	{
		//empty plus char
		//------------------------------------------------------
		// SETUP FIXTURE
		String  str1;
		String str2('a');

		// TEST
		String result = str1.operator+(str2);

		// VERIFY
		//assert(str1 == "");
		//assert(str2 == 'a');
		assert(result == "a");
	}
	{
		//char plus empty
		//------------------------------------------------------
		// SETUP FIXTURE
		String  str1('a');
		String str2;

		// TEST
		String result = str1.operator+(str2);

		// VERIFY
		//assert(str1 == 'a');
		//assert(str2 == "");
		assert(result == "a");
	}
	{
		//char plus char
		//------------------------------------------------------
		// SETUP FIXTURE
		String  str1('a');
		String str2('b');

		// TEST
		String result = str1.operator+(str2);

		// VERIFY
		//assert(str1 == 'a');
		//assert(str2 == 'b');
		assert(result == "ab");
	}
	{
		//word plus empty
		//------------------------------------------------------
		// SETUP FIXTURE
		String  str1("abc");
		String str2;

		// TEST
		String result = str1.operator+(str2);

		// VERIFY
		assert(str1 == "abc");
		//assert(str2 == "");
		assert(result == "abc");
	}
	{
		//empty plux word
		//------------------------------------------------------
		// SETUP FIXTURE
		String  str1;
		String str2("abc");

		// TEST
		String result = str1.operator+(str2);

		// VERIFY
		assert(str1 == "");
		assert(str2 == "abc");
		assert(result == "abc");
	}
	{
		//word plus word
		//------------------------------------------------------
		// SETUP FIXTURE
		String  str1("abc");
		String str2("def");

		// TEST
		String result = str1.operator+(str2);

		// VERIFY
		assert(str1 == "abc");
		assert(str2 == "def");
		assert(result == "abcdef");
	}

    std::cout << "Done testing concatination String + String." << std::endl;
}

