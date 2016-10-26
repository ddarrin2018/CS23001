//  String class test program
//
//  Tests: char array + String
//

#include "string.hpp"
#include <cassert>
#include <iostream>

//===========================================================================
int main ()
{
	{
		
		
	}
	{
		//charArray plus empty String
		//------------------------------------------------------
		// SETUP FIXTURE
		char a[] = { 'a','b', 'c', '\0' };
		String str;

		// TEST
		String result = a + str; 

		// VERIFY
		assert((a[0] == 'a') && (a[1]=='b') && (a[2] == 'c') && (a[3] == 0));
		assert(str == "");
		assert(result == "abc");
	}

	{
		//charArray plus String 
		//------------------------------------------------------
		// SETUP FIXTURE
		char a[] = { 'a','b', 'c', '\0' };
		String str("def");

		// TEST
		String result = a + str;

		// VERIFY
		assert((a[0] == 'a') && (a[1] == 'b') && (a[2] == 'c') && (a[3] == 0));
		assert(str == "def");
		assert(result == "abcdef");
	}

	{
		//empty charArray plus String 
		//------------------------------------------------------
		// SETUP FIXTURE
		char a[5] = {0};
		String str("def");

		// TEST
		String result = a + str;

		// VERIFY
		assert(a[0] == 0);
		assert(str == "def");
		assert(result == "def");
	}

	{
		//"empty" chara array and String
		//------------------------------------------------------
		// SETUP FIXTURE
		char a[] = {0};
		String str("");

		// TEST
		String result = a + str;

		// VERIFY
		assert(a[0] == 0);
		assert(str == "");
		assert(result == "");
	}

	std::cout << "Done testing concatination charArray plus String" << std::endl;

}

