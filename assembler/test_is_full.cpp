//Stack class test program
//Tests: isFull() method test


#include "../string/string.hpp"
#include "stack.hpp"

int main() {

	//string stack empty
	//------------------------------------------------------
	// SETUP FIXTURE
	Stack<String> str_stack;

	// VERIFY
	assert(str_stack.isFull() == false);

	
	//string stack not empty
	//------------------------------------------------------
	// SETUP FIXTURE
	str_stack.push("hello");

	// VERIFY
	assert(str_stack.isFull() == false);


	std::cout << "Done testing isFull() method." << std::endl;


}
