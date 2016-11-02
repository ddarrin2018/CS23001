#include "string.hpp"
//Test:     String        (const String&);                  //Copy Constructor.
int main() {
	{
		// Setup
		String a("abc");
		String b(a);

		// Verify
		assert(a == b);
	}
	{
		// Setup
		String a;
		String b(a);

		// Verify
		assert(a == b);
	}

	std::cout << "done testing copy constructor" << std::endl; 

}