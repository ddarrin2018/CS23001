//Stack class test program
//Tests: assignment


#include "../string/string.hpp"
#include "stack.hpp"

int main() {
	{
		//int stack, result was empty
		//------------------------------------------------------
		// SETUP FIXTURE
		Stack<int> integer_stack;
		integer_stack.push(1);
		integer_stack.push(25667);
		integer_stack.push(3);

		
		// TEST
		Stack<int> result;
		result = integer_stack;

		int third = result.pop();

		int second = result.pop();

		int first = result.pop();

		// VERIFY
		assert(first == 1);
		assert(second == 25667);
		assert(third == 3);
		assert(result.isEmpty());
		assert(integer_stack.isEmpty() == false);
	}

	{
		//double stack, result had same number of nodes
		//------------------------------------------------------
		// SETUP FIXTURE
		Stack<double> double_stack;
		double_stack.push(1.5987654);

		// TEST
		Stack<double> result;
		result.push(1.33);
		result = double_stack;
		double first_d = result.pop();



		// VERIFY
		assert(first_d == 1.5987654);
		assert(result.isEmpty());
		assert(double_stack.isEmpty() == false);
	}

	{
		//bool stack
		//------------------------------------------------------
		// SETUP FIXTURE
		Stack<bool> bool_stack;
		bool_stack.push(true);
		bool_stack.push(false);
		bool_stack.push(false);

		// TEST
		Stack<bool> result = bool_stack;

		bool third_b = result.pop();

		bool second_b = result.pop();

		bool first_b = result.pop();

		// VERIFY
		assert(first_b == true);
		assert(second_b == false);
		assert(third_b == false);
		assert(result.isEmpty());
		assert(bool_stack.isEmpty() == false);
	}

	{
		//string stack, result had more nodes
		//------------------------------------------------------
		// SETUP FIXTURE
		Stack<String> str_stack;
		str_stack.push("");
		str_stack.push("second");
		str_stack.push("third fourth fifth sixth seventh eigth ninth tenth eleventh twelfth thirteenth");

		// TEST
		Stack<String> result;
		result.push("abc");
		result.push("def");
		result.push("ghi");
		result.push("jkl"); 
		
		result = str_stack;

		String third_s = str_stack.pop();
		String third_r = result.pop();

		String second_s = str_stack.pop();
		String second_r = result.pop();

		String first_s = str_stack.pop();
		String first_r = result.pop();

		// VERIFY
		assert(first_s == "" && first_r == "");
		assert(second_s == "second" && second_r == "second");
		assert(third_s == "third fourth fifth sixth seventh eigth ninth tenth eleventh twelfth thirteenth" &&
			   third_r == "third fourth fifth sixth seventh eigth ninth tenth eleventh twelfth thirteenth");
		assert(str_stack.isEmpty() && result.isEmpty());
	}

	std::cout << "Done testing copy constructor. " << std::endl;
}
