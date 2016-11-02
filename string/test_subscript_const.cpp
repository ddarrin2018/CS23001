#include "string.hpp"
//Tests: char    operator[]    (int)                     const;  //Accessor
int main() {
	{
		// Setup
		String const str1("abc");

		// Test 
		char ch = str1[0];

		// Verify
		assert(str1 == "abc");
		assert(ch == 'a');
	}
	{
		// Setup
		String  const str1("abc");

		// Test 
		char ch = str1[1];

		// Verify
		assert(str1 == "abc");
		assert(ch == 'b');
	}
	{
		// Setup
		String const str1("abc");

		// Test 
		char ch = str1[2];

		// Verify
		assert(str1 == "abc");
		assert(ch == 'c');
	}
	//throws an error because? 
	/*
	{
		// Setup
		String const str1("abc");

		// Test 
		char ch = str1[3];

		// Verify
		assert(str1 == "abc");
		assert(ch == '\0');
	}
	*/

	std::cout << "finished testing subscript const" << std::endl;

}