/**
 *Marianna Matousek
 *bigint.cpp
 *CS23001
 *This is the implementation file for an ADT that can take any size
 *positive integer
 */


#include "bigint.hpp"



//initializes a bigintArray to 0
bigint::bigint() {
  for (int i = 0; i < SIZE; ++i) {
    bigintArray[i] = 0;
  }
}


//sets the bigintArray to the value of the int parameter
bigint::bigint(int num) : bigint() {
  int i = 0; //index
  int quotient = num;

  while (quotient != 0) {//if num is 0 leaves array as is after default constructor
    bigintArray[i] = quotient % 10; //sets the rightmost digit of num
    quotient /= 10; //digits yet to be entered into bigintArray
    i++;
  }
}

//sets the bigintArray to the int values of char[]
//Do I have to check if charString[] length is > SIZE?
bigint::bigint(const char charString[]) :bigint() {
  //find size of string
  int length = 0;
  while (charString[length] != 0) {
    length++;
  }
  //convert chars to ints and initialze bigintArray with the values
  int charStringIndex = length - 1;//starts at end of char[]
  for (int i = 0; i < length; i++) {
    bigintArray[i] = (charString[charStringIndex - i] - '0');

  }


}

//compares elements of two bigint arrays
bool  bigint::operator==(const bigint & rhs) const {//make &
  bool result = true;

  for (int i = 0; i < SIZE; ++i) {
    if (rhs.bigintArray[i] != bigintArray[i]) {
      result = false;
      break;//could I put a return statement here? //add a return 
    }
  }
  return result;
}

std::ostream& operator<<(std::ostream& out, const bigint & rhs) {//how could you make this a free function?
  bool found = false; //true after number other than 0 is encountered
  int digits_printed = 0;
  for (int i = (SIZE - 1); i >= 0; --i) {
    //prevents leading 0s from printing
    if (rhs.bigintArray[i] != 0) {
      found = true;
    }

    if (found == true) {
      //prints a new line after every 50 digits printed to screen
      if (digits_printed == 50) {
	out << "\n";
	digits_printed = 0;
      }

      out << rhs.bigintArray[i];
      digits_printed++;
    }
  }
  if (found == false)//if for loop found no digits other than 0
    out << 0;
  return out;

}


//returns the i-th digit where i is the 10^i position
int bigint::operator[](int index)const {
  return bigintArray[index];
}

std::istream& operator >> (std::istream & in, bigint & bi) {
  int input[SIZE];//temp array to hold input

  char ch;
  //inputs first char if at start of file
  //jumps over ';' if not at start
  in >> ch;
  if (in.eof()) {
    return in; 
  }

  int len = 0; //length of input
  while (ch != ';') {
    input[len] = ch - '0';
    in >> ch;
    ++len;
  }

  //iterating back from input[] and forward through bigint[]
  //inputing bigint values
  for (int i = len - 1, j = 0; i >= 0; --i, ++j) {
    bi.bigintArray[j] = input[i];

  }
  //need i check for end of file or is that main()'s responsibility?
  return in;


}

bigint bigint::operator+(const bigint & rhs)const {
  bigint result;
  int sum = 0;
  int remainder = 0;
  int carry = 0;

  //itterating through elements adds the values in rhs
  //and bigintArray and places the sum in result
  for (int i = 0; i < SIZE; ++i) {

    sum = bigintArray[i] + rhs[i] + carry;
    remainder = sum % 10;//ones digit
    carry = sum / 10; //tens
    result.bigintArray[i] = remainder;

  }


  return result;
}

//returns an bigint multiplies by 10^n with n>0
bigint bigint::times10(int exponent) const {
  bigint result;
  for (int i = 0; i < SIZE; ++i) {
    //adds necessary zeroes
    if (i < exponent) {
      result.bigintArray[i] = 0;
    }
    //assigns values of bigintArray to result after the zeroes 
    else {
      result.bigintArray[i] = bigintArray[i - exponent];
    }
  }
  return result; 
}

//multiplies a bigint and a single digit integer between 0 and 9
bigint bigint::times_single_digit(int digit)const {
  bigint result;
  int product = 0;
  int remainder = 0;//one of the product
  int carry = 0;//tens of the product

  for (int i = 0; i < SIZE; ++i) {
    product = bigintArray[i] * digit + carry;
    remainder = product % 10;
    carry = product / 10; 
    result.bigintArray[i] = remainder;
  }

  return result; 

}

//multiplies two bigints together
bigint bigint::operator*(const bigint & rhs)const {
  bigint result;
  for (int i = 0; i < SIZE; ++i) {

    //mulitiplies the bigintArray by each digit of the rhs.bigintArray
    bigint product = times_single_digit(rhs.bigintArray[i]);

    //multiplies the product by 10^i and adds to running total
    result = result + product.times10(i);
  }

  return result; 
}

//============//extra credit//========================================//


//subtracts two bigints together(very messily, i'm tired)
//correct only if difference is >= 0
bigint bigint::operator-(const bigint & rhs)const {
  bigint result;
  int difference = 0;
  int carry = 0;
  int remainder = 0;

  for (int i = 0; i < SIZE; ++i) {
    difference = 10 - rhs[i] + bigintArray[i] + carry; 

    //if the extra 10 was needed to get a positive number
    //take a ten away from next index
    if (difference < 10) {
      carry = -1;
    }
    //if it wasn't needed don't do anything because
    else {
      carry = 0;
    }
    //the ones digit is the same either way
    remainder = difference % 10; 

    result.bigintArray[i] = remainder; 
  }

  return result;
}

//returns a bigint holding the value
//of bigint factorial
bigint bigint::factorial()const {
  //is this allowed?
  bigint result = *this; 
  
  bigint temp = result - 1; 

  //since we dobn't have a > operator
  //and since 0! = 1:

  //while not equal to zero
  while (!(temp == 0)) {
    //multiply the result by bigint - 1
    result = result * temp; 
    temp = temp - 1;
  }

  return result;
}

//returns number of trailing zeroes
int bigint::trailing_zeroes()const {
  //number of zeroes and index
  int total = 0;
  bigint factorial = this->factorial();
  while (factorial.bigintArray[total] == 0) {
    total += 1;
  }

  return total; 
}
