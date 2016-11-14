//Stack class test program
//Tests: top() method


#include "string\string.hpp"
#include "stack.hpp"

int main() {
	//int stack
	//------------------------------------------------------
	// SETUP FIXTURE
	Stack<int> integer_stack;
	integer_stack.push(1);
	integer_stack.push(2);
	integer_stack.push(3);
	
	// TEST
	int third = integer_stack.top();
	integer_stack.pop();

	int second = integer_stack.top();
	integer_stack.pop();

	int first = integer_stack.top();

	// VERIFY
	assert(first == 1);
	assert(second == 2);
	assert(third == 3);

	//double stack
	//------------------------------------------------------
	// SETUP FIXTURE
	Stack<double> double_stack;
	double_stack.push(1.5);
	double_stack.push(2.5);
	double_stack.push(3.5);

	// TEST
	double third_d = double_stack.top();
	double_stack.pop();

	double second_d = double_stack.top();
	double_stack.pop();

	double first_d = double_stack.top();

	// VERIFY
	assert(first_d == 1.5);
	assert(second_d == 2.5);
	assert(third_d == 3.5);


	//bool stack
	//------------------------------------------------------
	// SETUP FIXTURE
	Stack<bool> bool_stack;
	bool_stack.push(true);
	bool_stack.push(false);
	bool_stack.push(false);

	// TEST
	bool third_b = bool_stack.top();
	bool_stack.pop();

	bool second_b = bool_stack.top();
	bool_stack.pop();

	bool first_b = bool_stack.top();

	// VERIFY
	assert(first_b == true);
	assert(second_b == false);
	assert(third_b == false);


	//int stack
	//------------------------------------------------------
	// SETUP FIXTURE
	Stack<String> str_stack;
	str_stack.push("first");
	str_stack.push("second");
	str_stack.push("third");

	// TEST
	String third_word = str_stack.top();
	str_stack.pop();

	String second_word = str_stack.top();
	str_stack.pop();

	String first_word = str_stack.top();

	// VERIFY
	assert(first_word == "first");
	assert(second_word == "second");
	assert(third_word == "third");


	std::cout << "Done testing top() method." << std::endl;


}

