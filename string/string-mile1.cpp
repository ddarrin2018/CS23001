/*Marianna Matousek
*10/14/2016
*string-mile1.cpp
*/

#include "string-mile1.hpp"

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

//Accessor/Modifier
//char& String::operator[](int) {
	//
//}

//Accessor
//char operator[](int i)const {
	//assert(i >= 0);
	//assert(i < length());
//} 






