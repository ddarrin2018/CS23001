/*Marianna Matousek
*10/14/2016
*string-mile1.cpp
*/

#include "string.hpp"

//empty string
String::String() {
	str[0] = 0; 
}

//String('x')
String::String(char ch) {
	str[0] = ch;
	str[1] = 0;
}

//Max chars that can be stored (not including null terminator)
int String::capacity() const{
	return (STRING_SIZE - 1);
}

//Number of char in string
int String::length() const {
	int i = 0;
	while (str[i] != 0) {
		++i;
	}
	return i; 
}


//String("abcd")
String::String(const char word[]) {
	int i = 0;
	while (word[i] != 0) {
		str[i] = word[i];
		i++;
		//if word is longer that array
		if (i >= capacity()) {
			break;
		}
		str[i] = 0;
	}
}

/*X-Ask about these to operators*/
//Accessor/Modifier
char& String::operator[](int i) {
	assert(i >= 0);
	assert(i <= length()); 
	return str[i];
}

//Accessor
char String::operator[](int i)const {
	assert(i >= 0);
	assert(i < length());
	return str[i];
} 

//Concatenation
String  String::operator+(const String& rhs)  const {
	String result(str);
	int offset = result.length();

	int i = 0;
	while (rhs.str[i] != 0) {
		result.str[offset + i] = rhs.str[i];
		++i;
	}
	result.str[offset + i] = 0;

	return result;
}

//Concatenation
String& String::operator+=(String rhs) {
	
	int offset = length();

	int i = 0;
	while (rhs.str[i] != 0) {
		str[offset + i] = rhs.str[i];
		++i;
	}
	str[offset + i] = 0;

	return *this;

}





