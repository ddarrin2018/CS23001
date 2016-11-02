#include "string.hpp"
//testing: char&   operator[]    (int);                            //Accessor/Modifier.

int main() {
	{
		// Setup
		String str1("abc");

		// Test 
		char ch = str1[0];

		// Verify
		assert(str1 == "abc");
		assert(ch == 'a');
	}
	{
		// Setup
		String str1("abc");

		// Test 
		char ch = str1[1];

		// Verify
		assert(str1 == "abc");
		assert(ch == 'b');
	}
	{
		// Setup
		String str1("abc");

		// Test 
		char ch = str1[2];

		// Verify
		assert(str1 == "abc");
		assert(ch == 'c');
	}
	{
		// Setup
		String str1("abc");

		// Test 
		char ch = str1[3];

		// Verify
		assert(str1 == "abc");
		assert(ch == '\0');
	}

	std::cout << "finished testing subscript" << std::endl;

}