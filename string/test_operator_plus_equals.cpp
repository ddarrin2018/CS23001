//  String class test program
//
//  Tests:  String& operator+=    (String)
//

#include "string.hpp"
#include <cassert>
#include <iostream>

//===========================================================================
int main ()
{
    {
		//empty String += String
        //------------------------------------------------------
        // SETUP FIXTURE
        String str1;
		String str2("def");

        // TEST
        String result = str1.operator+=(str2);

        // VERIFY
        assert(str1 == "def");
		assert(str2 == "def");
        assert(result == "def");
    }
	{
		//String += empty String
		//------------------------------------------------------
		// SETUP FIXTURE
		String str1("abc");
		String str2;

		// TEST
		String result = str1.operator+=(str2);

		// VERIFY
		assert(str1 == "abc");
		assert(str2 == "");
		assert(result == "abc");
	}
   
	{
		//String += String
		//------------------------------------------------------
		// SETUP FIXTURE
		String str1("abc");
		String str2("def");

		// TEST
		String result = str1.operator+=(str2);

		// VERIFY
		assert(str1 == "abcdef");
		assert(str2 == "def");
		assert(result == "abcdef");
	}

	{
		//empty String += empty String
		//------------------------------------------------------
		// SETUP FIXTURE
		String str1;
		String str2;

		// TEST
		String result = str1.operator+=(str2);

		// VERIFY
		assert(str1 == "");
		assert(str2 == "");
		assert(result == "");
	}
	{
		//empty String += empty String
		//------------------------------------------------------
		// SETUP FIXTURE
		String str1("aaaaaaaaaaaabbbbbbbbbbbbbbbcccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc");
		String str2("dddddddddddddddddddddeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeefffffffffffffffffffffffffff");

		// TEST
		String result = str1.operator+=(str2);

		// VERIFY
		assert(str1 == "aaaaaaaaaaaabbbbbbbbbbbbbbbccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccdddddddddddddddddddddeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeefffffffffffffffffffffffffff");
		assert(str2 == "dddddddddddddddddddddeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeefffffffffffffffffffffffffff");
		assert(result == "aaaaaaaaaaaabbbbbbbbbbbbbbbccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccdddddddddddddddddddddeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeefffffffffffffffffffffffffff");
	}

    std::cout << "Done testing operator+=." << std::endl;
}

