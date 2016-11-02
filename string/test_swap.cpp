#include "string.hpp"
//testing:  void    swap          (String&);
int main() {

	{
		// Setup
		String a("abc");
		String b("def");

		//Test
		a.swap(b);

		// Verify
		assert(a == "def");
		assert(b == "abc");
	}

	{
		// Setup
		String a;
		String b("def");

		//Test
		a.swap(b);

		// Verify
		assert(a == "def");
		assert(b == "");
	}

	{
		// Setup
		String a;
		String b("def");

		//Test
		b.swap(a);

		// Verify
		assert(a == "def");
		assert(b == "");
	}
	{
		// Setup
		String a("abc");
		String b("def");

		//Test
		b.swap(a);

		// Verify
		assert(a == "def");
		assert(b == "abc");
	}
	{
		// Setup
		String a;
		String b;

		//Test
		a.swap(b);

		// Verify
		assert(a == "");
		assert(b == "");
	}

	std::cout << "finished testing swap" << std::endl;
}