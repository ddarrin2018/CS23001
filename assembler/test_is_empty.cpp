//Stack class test program
//Tests: isEmpty() method test


#include "../string/string.hpp"
#include "stack.hpp"

int main() {

	//isEmpty() int not empty
	//------------------------------------------------------
	// SETUP FIXTURE
	Stack<int> integer_stack;
	integer_stack.push(9);
	
	// VERIFY
	assert(integer_stack.isEmpty() == false);

	//int stack back to empty
	// TEST
	int num = integer_stack.pop();

	// VERIFY
	assert(num == 9);
	assert(integer_stack.isEmpty());


	//isEmpty() double not empty
	//------------------------------------------------------
	// SETUP FIXTURE
	Stack<double> double_stack;
	double_stack.push(9.9);

	// VERIFY
	assert(double_stack.isEmpty() == false);

	//double stack back to empty
	// TEST
	double d_num= double_stack.pop();

	// VERIFY
	assert(d_num == 9.9);
	assert(double_stack.isEmpty());


	//isEmpty() bool not empty
	//------------------------------------------------------
	// SETUP FIXTURE
	Stack<bool> bool_stack;
	bool_stack.push(true);

	// VERIFY
	assert(bool_stack.isEmpty() == false);

	//bool stack back to empty
	// TEST
	bool b = bool_stack.pop();

	// VERIFY
	assert(b == true);
	assert(double_stack.isEmpty());



	//isEmpty() string stack not empty
	//------------------------------------------------------
	// SETUP FIXTURE
	Stack<String> str_stack;
	str_stack.push("hello");

	// VERIFY
	assert(str_stack.isEmpty() == false);

	//string stack back to empty
	// TEST
	String str = str_stack.pop();

	// VERIFY
	assert(str == "hello");
	assert(str_stack.isEmpty());


	std::cout << "Done testing isEmpty() method." << std::endl;


}

