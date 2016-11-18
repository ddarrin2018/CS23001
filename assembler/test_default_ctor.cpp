//Stack class test program
//Tests: default constructor


#include "../string/string.hpp"
#include "stack.hpp"

int main() {
	//Default constructor int
	//------------------------------------------------------
	// SETUP FIXTURE

	// TEST
	Stack<int> integer_stack;

	// VERIFY
	assert(integer_stack.isEmpty());

	//Default constructor double
	//------------------------------------------------------
	// SETUP FIXTURE

	// TEST
	Stack<double> double_stack;

	// VERIFY
	assert(double_stack.isEmpty());


	//Default constructor bool	
	//------------------------------------------------------
	// SETUP FIXTURE

	// TEST
	Stack<bool> bool_stack;

	// VERIFY
	assert(bool_stack.isEmpty());

	//Default constructor String
	//------------------------------------------------------
	// SETUP FIXTURE

	// TEST
	Stack<String> str_stack;

	// VERIFY
	assert(str_stack.isEmpty());


	std::cout << "Done testing default constructor." << std::endl;


}

