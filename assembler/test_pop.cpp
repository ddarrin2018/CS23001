//Stack class test program
//Tests: pop() method


#include "../string/string.hpp"
#include "stack.hpp"

int main() {
	//int stack pop off stack wiht one node
	//------------------------------------------------------
	// SETUP FIXTURE
	Stack<int> integer_stack;

	integer_stack.push(25667);


	// TEST

	int num = integer_stack.pop();


	// VERIFY
	
	assert(num == 25667);
	
	assert(integer_stack.isEmpty());


	//double stack pop off stack with two nodes
	//------------------------------------------------------
	// SETUP FIXTURE
	Stack<double> double_stack;
	double_stack.push(1.5987654);
	double_stack.push(2.5987654);

	// TEST
	double second_d = double_stack.pop();
	double first_d = double_stack.top();
	



	// VERIFY
	assert(second_d == 2.5987654);
	assert(first_d == 1.5987654);
	assert(double_stack.isEmpty()== false);






	//string stack pop of stack of length three
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

	std::cout << "Done testing pop() method." << std::endl;


}

