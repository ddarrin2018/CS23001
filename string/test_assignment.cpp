#include "string.hpp"
//Testing: String& operator=     (String);
int main() {
	{
		// Setup
		String a("abc");
		String b;

		//Test
		b = a;

		// Verify
		assert(a == "abc");
		assert(b == "abc");
	}
	{
		// Setup
		String a("abc");
		String b("def");

		//Test
		b = a;

		// Verify
		assert(a == "abc");
		assert(b == "abc");
	}
	{
		// Setup
		String a("abccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc");
		String b("def");

		//Test
		b = a;

		// Verify
		assert(a == "abccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc");
		assert(b == "abccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc");
	}
	{
		// Setup
		String a;
		String b("abc");

		//Test
		b = a;

		// Verify
		assert(a == "");
		assert(b == "");
	}
	
	
	std::cout << "done testing assignment operator" << std::endl;
}