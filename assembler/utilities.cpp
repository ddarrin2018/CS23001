#include "utilities.hpp"
#include "../string/string.hpp"

//free function that converts infix to postfix
String inToPost(String infix) {
		
	std::vector<String>  tokens = infix.split(' ');
		
	Stack<String> temp;
	
	size_t limit = tokens.size() -1;
	if (infix.findchar(0, ';') == -1) {
		limit = tokens.size();
	}

	for (size_t i = 0; i < limit; i++) { 
												   
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