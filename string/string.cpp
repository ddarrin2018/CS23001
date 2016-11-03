/*Marianna Matousek
*10/14/2016
*string.cpp
*milestone 2
*/

#include "string.hpp"
#include <cassert>
//empty string
String::String() {
	stringSize = 1; 

	//allocates memory for one element
	str = new char[1]; 
	
	//puts an null char at the elocated element
	str[0] = '\0';//same as *str = '\0' ? 
}

//Number of char in string
int String::length() const {
	int i = 0;
	while (str[i] != 0) {
		++i;
	}
	return i;
}

//Max chars that can be stored (not including null terminator)
int String::capacity() const {
	return (stringSize - 1);
}


//Destructor
String::~String() {
	delete [] str; 
}

//private sets capacity of string to n//
String::String(int n) {
	stringSize = n+1;
	str = new char[stringSize];
	str[n] = '\0';
}

/*Same as a[] ?*/
//String b(a.capcity(), a.str);  //A copy of string a.
//if n > num of chars in char* then 
String::String(int n, const char* a):String(n) {
	//copies over elements of a?
	for (int i = 0; i < length(); ++i) {
		if (a[i] != '/0') {
			str[i] = a[i];
		}
	}
	
}

//String('x')
String::String(char ch):String(1) {
	//sets capacity/length
	//puts null at pos 1
	//String(1);

	str[0] =  ch;
}


//String("abcd")
String::String(const char * word){
	//find length of word
	int length = 0;
	while (word[length] != 0) {
		length++;
	}

	
	//*this = String(length, word); //<- doesn't work sometimes

	
	stringSize = length+1;
	str = new char[stringSize];

	for (int i = 0; i < length; ++i) {
		str[i] = word[i];
	}

	//null char
	str[length] = 0; 
	
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

//copy constructor
String::String(const String& actual) {
	stringSize = actual.stringSize;
	str = new char[stringSize];
	for (int i = 0; i < stringSize; ++i) {
		str[i] = actual.str[i];
	}
}

//assignment
String& String::operator=(String s) {
	swap(s);
	return *this;
}


void    String::swap(String& rhs) {
	char *temp_str = str;
	int temp_stringSize = stringSize;
	
	str = rhs.str; 
	stringSize = rhs.stringSize;

	rhs.str = temp_str;
	rhs.stringSize = temp_stringSize; 
}

String  String::operator+(const String& rhs)const {
	String result(length()+rhs.length(), str);

	int offset = length(); 
	for (int i = 0; i < rhs.length(); ++i) {
		result[offset + i] = rhs.str[i];
   }
	return result; 
}

String& String::operator+=    (String rhs) {
	int offset = length();

	//make current capacity equal to the combined capacities
	//and keep all the current char values where they are
	*this = String(length() + rhs.length(), str);
	
	for (int i = 0; i < rhs.length(); ++i) {
		str[offset + i] = rhs.str[i];
	}
	return *this; 
}


/*I feel like I'm not doing the right thing with this one:*/
std::istream& operator >> (std::istream& in, String& rhs) {
	 
	char ch; 
	in.get(ch);

	//make rhs an empty string 
	rhs = String();

	//if its not eof or null or new line add char to rhs
	//newline was giving me issues for some reason
	while (ch !=0 && !in.eof() && ch != '\n')
	{
		rhs += ch; 
		in.get(ch);
	
	}
	
	

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

//resets capacity to int
void    String::resetCapacity(int n) {
	if (n > length()) {
		*this = String(n, str);
	}
}


bool String::operator<(const String& rhs) const {
	//check which is longer
	int conditional_length;
	if (length() <= rhs.length()) {
		conditional_length = length();
	}
	//rhs.length()>lenght()
	else {
		conditional_length = rhs.length();
	}

	//only loop up to the shortest tring
	for (int i = 0; i < conditional_length; ++i) {
		if (str[i] < rhs.str[i]) {
			return true;
		}
	}
	if (conditional_length == 0) {
		return (str[0] < rhs.str[0]);
	}
	return false;
}



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
	//create a string result of needed capacity
	String result(end - start + 1);
	int j = 0;
	for (int i = start; i <= end; ++i) {
		result[j] = str[i];
		++j;
	}

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


String  operator+(const char* s_array, const String& s) {
	//convert char array into a String object
	String result(s_array);  
	//concatinate the two 
	result = result + s; 
	return result; 
}



String  operator+ (char ch, const String& s) {
	String result(ch); 
	result += s; 
	return result; 
}




bool operator==(const char* arr, const String& s) {
	//convert char array into a string obj
	String temp(arr);

	//compare the two obejcts 
	return (s == temp);
}


bool    operator== (char ch, const String& s) {
	String temp(ch);

	//compare the two objects
	return(temp == s);
}

bool    operator<       (const char* arr, const String&s) {
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

