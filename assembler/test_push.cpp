//Stack class test program
//Tests: push() method


#include "string\string.hpp"
#include "stack.hpp"

int main() {
	//int stack
	//------------------------------------------------------
	// SETUP FIXTURE
	Stack<int> integer_stack;
	integer_stack.push(1);
	integer_stack.push(25667);
	integer_stack.push(0);

	// TEST
	int third = integer_stack.pop();
	  
	int second = integer_stack.pop();

	int first = integer_stack.pop();

	// VERIFY
	assert(first == 1);
	assert(second == 25667);
	assert(third == 0);
	assert(integer_stack.isEmpty());


	//double stack
	//------------------------------------------------------
	// SETUP FIXTURE
	Stack<double> double_stack;
	double_stack.push(1.5987654);

	// TEST
	double first_d = double_stack.pop();



	// VERIFY
	assert(first_d == 1.5987654);
	assert(double_stack.isEmpty());
	


	//bool stack
	//------------------------------------------------------
	// SETUP FIXTURE
	Stack<bool> bool_stack;
	bool_stack.push(true);
	bool_stack.push(false);
	bool_stack.push(false);

	// TEST
	bool third_b = bool_stack.pop();

	bool second_b = bool_stack.pop();

	bool first_b = bool_stack.pop();

	// VERIFY
	assert(first_b == true);
	assert(second_b == false);
	assert(third_b == false);
	assert(bool_stack.isEmpty());


	//int stack
	//------------------------------------------------------
	// SETUP FIXTURE
	Stack<String> str_stack;
	str_stack.push("");
	str_stack.push("second");
	str_stack.push("third fourth fifth sixth seventh eigth ninth tenth eleventh twelfth thirteenth");

	// TEST
	String third_word = str_stack.pop();

	String second_word = str_stack.pop();

	String first_word = str_stack.pop();

	// VERIFY
	assert(first_word == "");
	assert(second_word == "second");
	assert(third_word == "third fourth fifth sixth seventh eigth ninth tenth eleventh twelfth thirteenth");
	assert(str_stack.isEmpty());

	std::cout << "Done testing push() method." << std::endl;


}

