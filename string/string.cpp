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
int String::capacity() const {
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
String::String(const char word[]): String(){
	int i = 0;
	while (word[i] != 0) {///changed
		str[i] = word[i];
		i++;
		//if word is longer that array
		if (i >= capacity()) {
			break; 
		}
		str[i] = 0;
	}
}

/*X-Ask about these two operators*/
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
/*Why isn't this String& ?*/
String& String::operator+=(String rhs) {

	int offset = length();

	int i = 0;
	while (rhs.str[i] != 0) { //and i + offset < capacity()
		str[offset + i] = rhs.str[i];
		++i;
	}
	str[offset + i] = 0;

	return *this;

}

bool String::operator==(const String& rhs)  const {
	//if strings don't have same length
	if (length() != rhs.length()) {
		return false;
	}

	//if they have same length checks elements
	for (int i = 0; i < length(); ++i) {
		if (str[i] != rhs[i]) {
			return false;
		}
	}

	//if length and elements same
	return true;
}


bool String::operator<(const String& rhs)const {
	//lhs string is assumed to be lessthan rhs
	if (length() < rhs.length()) {
		for (int i = 0; i < length(); ++i) {
			if (str[i] > rhs[i]) {
				return false;
			}
		}
		return true; 
	}
	//length >= rhs.length
	//lhs string is assumed to be greater than or equal to rhs
	else {
		for (int i = 0; i < rhs.length(); ++i) {
			if (str[i] < rhs[i]) {
				return true;
			}
			return false;
		}


	}
}

std::ostream& operator<<(std::ostream& out, const String& rhs) { //This is a friend function.
	out << rhs.str;
	return out;
}


std::istream& operator >> (std::istream& in, String& rhs) {
	char temp[500];
	in >> temp;   //Skips leading whitespace and read until next whitespace.
	rhs = String(temp);   //temp is null terminating 
	return in;
}

/*
//i feel like this is wrong:
std::istream& operator >> (std::istream& in, String& rhs) {
	char input[STRING_SIZE];
	char ch;

	in.get(ch);
	int i = 0;
	while (ch != '\0' && (!in.eof()) && i < (STRING_SIZE -1) && ch!= '\n') {
		input[i] = ch;
		in.get(ch);
		++i;
	}
	input[i] = '\0';

	rhs = String(input);

	return in;


	
}

std::ostream& operator << (std::ostream& out, const String& rhs) {
	for (int i = 0; i < rhs.length(); ++i) {
		if (rhs.str[i] != 0) {
			out << rhs.str[i];
		}
		
	}


	return out;
}

*/

//Also implement methods for sub string, find string, and find character.
String String::substr(int start, int end)const {
	//if start <= 0
	if (start < 0) start = 0;

	//if start past end of string
	if (start > length()) return String();

	//if start is past the end 
	if (start > end) return String();

	//if end past end of string return empty
	/*Ask: why can't we just return from start to end of string?*/
	if (end >= length()) return String();

	String result;
	int j = 0;
	for (int i = start; i <= end; ++i) {
		result[j] = str[i];
		++j;
	}
	//NULL terminator
	result[j] = 0;

	return result;
}

//find string
//***Need to add error checking
int    String::findstr(int start, const String&s) const{
	//if start <= 0
	if (start < 0) start = 0;

	//if start past end of string
	if (start > length()) return -1;


	bool found = false;
	/**findchar() might simplify follwoing function*/
	//starting from position start until end of str find a match for
	//the first letter of the search word s
	for (int i = start, j = 0; i < length(); ++i) {
		int pos_found = i;
		
		//if first letter found
		if (str[i] == s[j]) {
			found = true; 
			//look for the rest of the search word letters
			while (j < s.length()) {
				
				//if letter is found search at next position
				//for the next letter of the search word
				if (str[i] == s[j]) {
					++i;
					++j;
				}
				//if a letter is not found restart search 
				//for the first letter of search word at
				//next position in str
				else {
					found = false;
					j = 0;
					break;
				}
			}
			//if we've found every character of search word
			if (found == true) {
				return pos_found;
			}

		}
		//if first letter not found look at next positon

	}
	
	//if after for loop search word is not found
	return -1;
}


int    String::findchar(int start, char ch) const {
	//starting from start to end of str search for ch
	for (int i = start; i < length(); ++i) {
		if (str[i] == ch) {
			return i; 
		}
	}

	//if ch not found
	return -1; 
}

//how to know if i should be doing char[] + String 
//has to have char s[] = { 'a', 'b', 'c', 0 };
//Or String + char[]
String  operator+(const char s_array[], const String& s) {
	//convert char array into a String object
	String result(s_array);  
	//concatinate the two 
	result = result + s; 
	return result; 
}

//should this be ch + String&
//or String& + ch
String  operator+ (char ch, const String& s) {
	String result(ch); 
	result += s; 
	return result; 
}


bool operator==(const char arr[], const String& s) {
	//convert char array into a String obj
	String temp(arr);

	//compare the two obejcts 
	return (s == temp);

}

bool    operator== (char ch, const String& s) {
	String temp(ch);

	//compare the two objects
	return(temp == s);

}

bool    operator<       (const char arr[], const String&s) {
	return(String(arr) < s);
}

bool    operator<  (char ch, const String& s) {
	return (String(ch) < s);
}


bool    operator<= (const String& lhs, const String& rhs) {
	return(lhs < rhs || lhs == rhs); 
}

bool    operator!=      (const String& lhs, const String& rhs) {
	return (!(lhs == rhs));
}

bool    operator>=      (const String& lhs, const String& rhs) {
	return (rhs < lhs || lhs == rhs);
}

bool    operator>       (const String& lhs, const String& rhs) {
	return (rhs < lhs);
}