#include "utilities.hpp"

//free function that converts infix to postfix
String inToPost(String infix) {
	std::vector<String>  tokens = infix.split(' ');
	Stack<String> temp;

	for (size_t i = 0; i < (tokens.size() - 1); i++) {//ignore last element 
												   //std::cout << "[" << tokens[i] << "] ";
		String token = tokens[i];

		if (token != ")") {
			if (token != "(") {
				temp.push(token);
			}

		}
		else {
			String right = temp.pop();
			String oper = temp.pop();
			String left = temp.pop();
			String result = left + " " + right + " " + oper;

			temp.push(result);
		}
	}



	return temp.top();
}